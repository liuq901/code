#include <cstdio>
#include <cstdlib>
#include <cstring>
const int inf=0x7FFFFFFF;
int n,b[210],a[15000][4];
int main()
{
   void add_edge(int,int,int);
   bool build();
   int dinic(int,int);
   int m,v[2][101];
   scanf("%d%d",&n,&m);
   for (int i=1;i<=n;i++)
      scanf("%d",&v[0][i]);
   for (int i=1;i<=n;i++)
      scanf("%d",&v[1][i]);
   for (int i=1;i<=m;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      add_edge(x,y+n,inf);
   }
   for (int i=1;i<=n;i++)
   {
      add_edge(0,i,v[1][i]);
      add_edge(i+n,2*n+1,v[0][i]);
   }
   int ans=0;
   while (build())
      ans+=dinic(0,inf);
   printf("%d\n",ans);
   bool f[210]={0};
   int l,r,q[210];
   l=r=1;
   q[1]=0;
   f[0]=true;
   while (l<=r)
   {
      int x=q[l];
      for (int i=b[x];i;i=a[i][3])
      {
         int y=a[i][0];
         if (f[y] || !a[i][1])
            continue;
         f[y]=true;
         q[++r]=y;
      }
      l++;
   }
   int sum=0;
   for (int i=1;i<=n;i++)
   {
      if (!f[i])
         sum++;
      if (f[i+n])
         sum++;
   }
   printf("%d\n",sum);
   for (int i=1;i<=n;i++)
   {
      if (!f[i])
         printf("%d -\n",i);
      if (f[i+n])
         printf("%d +\n",i);
   }
   system("pause");
   return(0);
}
void add_edge(int x,int y,int z)
{
   static int t=0;
   t++;
   a[2*t-1][0]=y;
   a[2*t-1][1]=z;
   a[2*t-1][2]=2*t;
   a[2*t-1][3]=b[x];
   b[x]=2*t-1;
   a[2*t][0]=x;
   a[2*t][1]=0;
   a[2*t][2]=2*t-1;
   a[2*t][3]=b[y];
   b[y]=2*t;
}
int d[210];
bool build()
{
   int l,r,q[210];
   q[1]=0;
   l=r=1;
   memset(d,0,sizeof(d));
   d[0]=1;
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
         if (y==2*n+1)
            return(true);
      }
      l++;
   }
   return(false);
}
int dinic(int x,int flow)
{
   int min(int,int);
   if (x==2*n+1)
      return(flow);
   int s=0,t=flow;
   for (int i=b[x];i;i=a[i][3])
   {
      int y=a[i][0];
      if (d[y]!=d[x]+1 || !a[i][1])
         continue;
      int k=dinic(y,min(t,a[i][1]));
      a[i][1]-=k;
      a[a[i][2]][1]+=k;
      s+=k;
      t-=k;
      if (!t)
         return(flow);
   }
   if (!s)
      d[x]=-1;
   return(s);
}
int min(int x,int y)
{
   return(x<y?x:y);
}
