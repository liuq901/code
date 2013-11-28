#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf=20262620;
int S,T,tot,x[110],y[110],b[210],a[1000000][3];
int main()
{
   void add(int,int,int);
   bool build();
   int dinic(int,int);
   while (1)
   {
      int l,w,n,d;
      scanf("%d%d%d%d",&l,&w,&n,&d);
      if (!l && !w && !n && !d)
         break;
      S=0,T=(n<<1)+1,tot=1;
      memset(b,0,sizeof(b));
      for (int i=1;i<=n;i++)
      {
         scanf("%d%d",&x[i],&y[i]);
         add(i,i+n,1);
         if (y[i]<=d)
            add(S,i,inf);
         if (y[i]+d>=w)
            add(i+n,T,inf);
      }
      for (int i=1;i<=n;i++)
         for (int j=i+1;j<=n;j++)
         {
            int dx=x[i]-x[j],dy=y[i]-y[j];
            if (dx*dx+dy*dy<=4*d*d)
            {
               add(i+n,j,inf);
               add(j+n,i,inf);
            }
         }
      int ans=0;
      while (build())
         ans+=dinic(S,inf);
      static int id=0;
      printf("Case %d: %d\n",++id,ans);
   }
   system("pause");
   return(0);
}
void add(int x,int y,int c)
{
   a[++tot][0]=y,a[tot][1]=c,a[tot][2]=b[x],b[x]=tot;
   a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],b[y]=tot;
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
