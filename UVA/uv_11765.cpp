#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf=(1<<30)-1;
int S,T,tot,b[210],e[210][2],a[1000000][3];
int main()
{
   void add(int,int,int,int);
   bool build();
   int dinic(int,int);
   int test;
   scanf("%d",&test);
   while (test--)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      S=0,T=n+1;
      memset(b,0,sizeof(b));
      tot=1;
      for (int i=1;i<=n;i++)
         scanf("%d",&e[i][0]);
      for (int i=1;i<=n;i++)
         scanf("%d",&e[i][1]);
      for (int i=1;i<=n;i++)
      {
         int x;
         scanf("%d",&x);
         if (x==1)
            add(S,i,e[i][0],0),add(i,T,inf,0);
         else if (x==-1)
            add(S,i,inf,0),add(i,T,e[i][1],0);
         else
            add(S,i,e[i][0],0),add(i,T,e[i][1],0);
      }
      for (int i=1;i<=m;i++)
      {
         int x,y,z;
         scanf("%d%d%d",&x,&y,&z);
         add(x,y,z,z);
      }
      int ans=0;
      while (build())
         ans+=dinic(S,inf);
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
void add(int x,int y,int c1,int c2)
{
   a[++tot][0]=y,a[tot][1]=c1,a[tot][2]=b[x],b[x]=tot;
   a[++tot][0]=x,a[tot][1]=c2,a[tot][2]=b[y],b[y]=tot;
}
int d[210],q[210];
bool build()
{
   int l,r;
   memset(d,0,sizeof(d));
   q[l=r=1]=S,d[S]=1;
   while (l<=r)
   {
      int x=q[l++];
      for (int i=b[x];i;i=a[i][2])
      {
         int y=a[i][0];
         if (d[y] || !a[i][1])
            continue;
         d[y]=d[x]+1;
         q[++r]=y;
         if (y==T)
            return(true);
      }
   }
   return(false);
}
int dinic(int x,int flow)
{
   if (x==T)
      return(flow);
   int k=flow;
   for (int i=b[x];i;i=a[i][2])
   {
      int y=a[i][0];
      if (d[y]!=d[x]+1 || !a[i][1])
         continue;
      int t=dinic(y,min(k,a[i][1]));
      k-=t;
      a[i][1]-=t;
      a[i^1][1]+=t;
      if (!k)
         return(flow);
   }
   if (k==flow)
      d[x]=-1;
   return(flow-k);
}
