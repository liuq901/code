#include <cstdio>
#include <cstdlib>
#include <cstring>
const int inf=1<<30;
int tot,b[70000],a[300000][4];
int main()
{
   void add(int,int);
   bool build();
   int dinic(int,int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      memset(b,0,sizeof(b));
      tot=0;
      for (int i=1;i<=m;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         if (x>n || y>n)
            continue;
         add(x,y+n);
         add(y,x+n);
      }
      for (int i=1;i<=n;i++)
         add(i+n,i);
      add(1,0);
      add(3,0);
      int ans=0;
      while (build())
         ans+=dinic(2,inf);
      printf("%s\n",ans==2?"YES":"NO");
   }
   system("pause");
   return(0);
}
void add(int x,int y)
{
   a[++tot][0]=y,a[tot][1]=1,a[tot][2]=tot+1,a[tot][3]=b[x],b[x]=tot;
   a[++tot][0]=x,a[tot][1]=0,a[tot][2]=tot-1,a[tot][3]=b[y],b[y]=tot;
}
int d[70000];
bool build()
{
   memset(d,0,sizeof(d));
   int l,r,q[70000];
   l=r=d[2]=1;
   q[1]=2;
   while (l<=r)
   {
      int x=q[l];
      for (int i=b[x];i;i=a[i][3])
      {
         int y=a[i][0];
         if (d[y] || !a[i][1])
            continue;
         d[y]=d[x]+1;
         q[++r]=y;
         if (!y)
            return(true);
      }
      l++;
   }
   return(false);
}
int dinic(int x,int flow)
{
   int min(int,int);
   if (!x)
      return(flow);
   int k=flow;
   for (int i=b[x];i;i=a[i][3])
   {
      int y=a[i][0];
      if (d[y]!=d[x]+1 || !a[i][1])
         continue;
      int t=dinic(y,min(k,a[i][1]));
      k-=t;
      a[i][1]-=t;
      a[a[i][2]][1]+=t;
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
