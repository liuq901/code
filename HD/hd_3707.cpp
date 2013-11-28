#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf=1<<30;
int n,a[40],g[40][40],b[40][40][40],f[40][40][40][3];
int main()
{
   void init();
   int solve(int,int,int,int);
   while (scanf("%d",&n)==1)
   {
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      sort(a+1,a+n+1);
      init();
      memset(f,-1,sizeof(f));
      memset(g,-1,sizeof(g));
      printf("%d\n",solve(1,n,1,2));
   }
   system("pause");
   return(0);
}
void init()
{
   memset(b,-1,sizeof(b));
   for (int i=1;i<=n;i++)
      for (int j=1;j<=i;j++)
         for (int k=i;k<=n;k++)
         {
            int dist=max(abs(a[i]-a[j]),abs(a[i]-a[k]));
            for (int l=1;l<=n;l++)
               if (abs(a[l]-a[i])<=dist)
                  b[i][j][k]++;
         }
}
int solve(int l,int r,int last,int state)
{
   int calc(int,int);
   int &ret=f[l][r][last][state];
   if (ret!=-1)
      return(ret);
   if (l==r)
      return(ret=state==1?0:b[l][last][r]);
   ret=inf;
   int now=!state?2:state;
   for (int i=l+1;i<=r;i++)
   {
      int cost=!state?0:b[l][last][i];
      ret=min(ret,calc(l,i)+solve(i,r,l,now)+cost);
   }
   return(ret);
}
int calc(int l,int r)
{
   int solve(int,int,int,int);
   int &ret=g[l][r];
   if (ret!=-1)
      return(ret);
   if (r-l<=1)
      return(ret=0);
   ret=inf;
   for (int i=l;i<r;i++)
      ret=min(ret,solve(l,i,l,0)+solve(i+1,r,i+1,1));
   return(ret);
}
