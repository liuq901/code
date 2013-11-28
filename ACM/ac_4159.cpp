#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int c[6][3]={{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
struct data
{
   int h,m,s;
   data(){}
   data(int h,int m,int s):h(h),m(m),s(s){}
};
data operator +(data a,int b)
{
   return(data((a.h+b)%60,(a.m+b)%60,(a.s+b)%60));
}
int operator -(data a,data b)
{
   return(a.s-b.s+(a.m-b.m)*60+(a.h/5-b.h/5)*3600);
}
bool operator <=(data a,data b)
{
   return(a.h<b.h || a.h==b.h && (a.m<b.m || a.m==b.m && a.s<=b.s));
}
data l,r;
int n,ans,a[20][3];
int main()
{
   void work(data);
   while (1)
   {
      scanf("%d",&n);
      if (!n)
         break;
      for (int i=1;i<=n;i++)
         scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
      ans=1<<30;
      l=data(59,59,59);
      for (int i=1;i<=n;i++)
         for (int j=0;j<60;j++)
            for (int k=0;k<6;k++)
            {
               int u=c[k][0],v=c[k][1],w=c[k][2];
               work(data(a[i][u],a[i][v],a[i][w])+j);
            }
      printf("%02d:%02d:%02d %02d:%02d:%02d\n",l.h/5,l.m,l.s,r.h/5,r.m,r.s);
   }
   system("pause");
   return(0);
}
void work(data now)
{
   bool check(data);
   if (!check(now))
      return;
   data p(0,0,0);
   for (int i=1;i<=n;i++)
   {
      data t(59,59,59);
      bool flag=true;
      for (int j=0;j<60;j++)
         for (int k=0;k<6;k++)
         {
            int u=c[k][0],v=c[k][1],w=c[k][2];
            data x=data(a[i][u],a[i][v],a[i][w])+j;
            if (!check(x))
               continue;
            if (now<=x)
            {
               flag=false;
               if (x<=t)
                  t=x;
            }
         }
      if (flag)
         return;
      if (p<=t)
         p=t;
   }
   if (p-now<ans)
      ans=p-now,l=now,r=p;
   else if (p-now==ans && now<=l)
      l=now,r=p;
}
bool check(data a)
{
   return(a.m/12==a.h%5);
}
