#include <cstdio>
#include <cstdlib>
#include <set>
#include <algorithm>
using namespace std;
const int inf=1<<30;
struct data
{
   int x0,y0,z0,x1,y1,z1;
   data(){}
   data(int a,int b,int c,int d,int e,int f)
   {
      x0=a,y0=b,z0=c,x1=d,y1=e,z1=f;
   }
};
bool operator <(data a,data b)
{
   if (a.x0!=b.x0)
      return(a.x0<b.x0);
   if (a.y0!=b.y0)
      return(a.y0<b.y0);
   if (a.z0!=b.z0)
      return(a.z0<b.z0);
   if (a.x1!=b.x1)
      return(a.x1<b.x1);
   if (a.y1!=b.y1)
      return(a.y1<b.y1);
   return(a.z1<b.z1);
}
set <data> p;
data now;
int s[30][10];
int main()
{
   void init(int,int,int,int,int,int);
   int n;
   scanf("%d",&n);
   init(1,2,3,4,5,6);
   int m=0;
   for (set <data>::iterator k=p.begin();k!=p.end();k++)
      s[++m][1]=k->x0,s[m][2]=k->y0,s[m][3]=k->z0,s[m][4]=k->x1,s[m][5]=k->y1,s[m][6]=k->z1;
   p.clear();
   for (int i=1;i<=n;i++)
   {
      int a,b,c,d,e,f;
      scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
      now=data(inf,inf,inf,inf,inf,inf);
      s[0][1]=a,s[0][2]=b,s[0][3]=c,s[0][4]=d,s[0][5]=e,s[0][6]=f;
      for (int j=1;j<=m;j++)
      {
         int q[10];
         for (int k=1;k<=6;k++)
            q[k]=s[0][s[j][k]];
         now=min(now,data(q[1],q[2],q[3],q[4],q[5],q[6]));
      }
      p.insert(now);
   }
   printf("%d\n",p.size());
   system("pause");
   return(0);
}
void init(int a,int b,int c,int d,int e,int f)
{
   data t(a,b,c,d,e,f);
   if (p.count(t))
      return;
   p.insert(t);
   now=min(now,t);
   init(b,d,c,e,a,f);
   init(c,b,d,f,e,a);
   init(a,c,e,d,f,b);
}
