#include <cstdio>
#include <cstdlib>
#include <cstring>
const int inf=(1<<30)-1;
int start,end,tot=1,b[20010],a[1000000][3];
int main()
{
   void add(int,int,int);
   bool build();
   int dinic(int,int);
   int limit,n,m;
   scanf("%d%d%d%d%d",&limit,&n,&m,&start,&end);
   if (start==end)
      printf("NO\n");
   else
   {
      for (int i=1;i<=n;i++)
      {
         int x;
         scanf("%d",&x);
         if (i==start || i==end)
            x=inf;
         add(i,i+n,x);
      }
      for (int i=1;i<=m;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         add(x+n,y,inf);
         add(y+n,x,inf);
      }
      int ans=0;
      while (build())
         ans+=dinic(start,inf);
      printf("%s\n",ans<=limit?"YES":"NO");
   }
   system("pause");
   return(0);
}
void add(int x,int y,int z)
{
   a[++tot][0]=y,a[tot][1]=z,a[tot][2]=b[x],b[x]=tot;
   a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],b[y]=tot;
}
int d[20010];
bool build()
{
   int l,r,q[20010];
   memset(d,0,sizeof(d));
   l=r=1,d[start]=1,q[1]=start;
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
         if (y==end)
            return(true);
      }
      l++;
   }
   return(false);
}
int dinic(int x,int flow)
{
   int min(int,int);
   if (x==end)
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
