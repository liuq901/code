#include <cstdio>
#include <cstdlib>
#include <cstring>
const int inf=(1<<30)-1;
int tot,n,b[1001],a[1000000][3];
int main()
{
   void add(int,int,int);
   bool build();
   int dinic(int,int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      tot=1;
      memset(b,0,sizeof(b));
      int m;
      scanf("%d%d",&n,&m);
      for (int i=1;i<n;i++)
      {
         int x;
         scanf("%d",&x);
         add(i+100,i,x);
      }
      add(n+100,n,inf);
      bool flag=false;
      for (int i=1;i<=m;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         add(x,y+100,inf);
         add(y,x+100,inf);
         if (abs(x+y)==n && abs(x-y)==n)
            flag=true;
      }
      if (flag)
      {
         printf("Max!\n");
         continue;
      }
      int ans=0;
      while (build())
         ans+=dinic(0,inf);
      if (!ans)
         printf("Min!\n");
      else
         printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
void add(int x,int y,int z)
{
   a[++tot][0]=y,a[tot][1]=z,a[tot][2]=b[x],b[x]=tot;
   a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],b[y]=tot;
}
int d[1001];
bool build()
{
   int l,r,q[1001];
   memset(d,0,sizeof(d));
   l=r=1,q[1]=0,d[0]=1;
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
         if (y==n)
            return(true);
      }
      l++;
   }
   return(false);
}
int dinic(int x,int flow)
{
   int min(int,int);
   if (x==n)
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
