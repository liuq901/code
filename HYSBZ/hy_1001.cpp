#include <cstdio>
#include <cstdlib>
#include <cstring>
const int inf=(1<<30)-1;
int tot=1,n,m,b[1000001],a[8000000][3];
int main()
{
   void add(int,int,int);
   bool build();
   int dinic(int,int);
   scanf("%d%d",&n,&m);
   for (int i=1;i<=n;i++)
      for (int j=2;j<=m;j++)
      {
         int x;
         scanf("%d",&x);
         add((i-1)*m+j-1,(i-1)*m+j,x);
      }
   for (int i=2;i<=n;i++)
      for (int j=1;j<=m;j++)
      {
         int x;
         scanf("%d",&x);
         add((i-2)*m+j,(i-1)*m+j,x);
      }
   for (int i=2;i<=n;i++)
      for (int j=2;j<=m;j++)
      {
         int x;
         scanf("%d",&x);
         add((i-2)*m+j-1,(i-1)*m+j,x);
      }
   int ans=0;
   while (build())
      ans+=dinic(1,inf);
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void add(int x,int y,int z)
{
   a[++tot][0]=y,a[tot][1]=z,a[tot][2]=b[x],b[x]=tot;
   a[++tot][0]=x,a[tot][1]=z,a[tot][2]=b[y],b[y]=tot;
}
int d[1000001],q[1000001];
bool build()
{
   int l,r;
   memset(d,0,sizeof(d));
   l=r=d[1]=q[1]=1;
   while (l<=r)
   {
      int x=q[l];
      for (int i=b[x];i;i=a[i][2])
      {
         int y=a[i][0];
         if (d[y] || !a[i][1])
            continue;
         d[y]=d[x]+1;
         q[++r]=y;
         if (y==n*m)
            return(true);
      }
      l++;
   }
   return(false);
}
int dinic(int x,int flow)
{
   int min(int,int);
   if (x==n*m)
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
int min(int x,int y)
{
   return(x<y?x:y);
}
