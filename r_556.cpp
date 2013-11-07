#include <cstdio>
#include <cstdlib>
#include <cstring>
const int inf=(1<<30)-1;
int tot=1,end,b[60000],a[1000000][3];
int main()
{
   void add(int,int,int);
   bool build();
   int dinic(int,int);
   int n,m;
   scanf("%d%d",&n,&m);
   end=n+m+1;
   for (int i=1;i<=n;i++)
   {
      int x;
      scanf("%d",&x);
      add(i+m,end,x);
   }
   int ans=0;
   for (int i=1;i<=m;i++)
   {
      int x,y,z;
      scanf("%d%d%d",&x,&y,&z);
      add(i,x+m,inf);
      add(i,y+m,inf);
      add(0,i,z);
      ans+=z;
   }
   while (build())
      ans-=dinic(0,inf);
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void add(int x,int y,int v)
{
   a[++tot][0]=y,a[tot][1]=v,a[tot][2]=b[x],b[x]=tot;
   a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],b[y]=tot;
}
int q[60000],d[60000];
bool build()
{
   int l,r;
   memset(d,0,sizeof(d));
   d[0]=l=r=1,q[1]=0;
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
