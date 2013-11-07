#include <cstdio>
#include <cstdlib>
#include <cstring>
const int inf=20000000;
int n,d[1001],w[1001],in[1001],out[1001],b[1001],dist[1001][1001];
int dep[1001],fa[1001],v[1001],g[1001],a[2001][3],f[1001][1001];
int main()
{
   void floodfill(int,int);
   int count(int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
         scanf("%d",&w[i]);
      for (int i=1;i<=n;i++)
         scanf("%d",&d[i]);
      memset(b,0,sizeof(b));
      for (int i=1;i<n;i++)
      {
         int x,y,z;
         scanf("%d%d%d",&x,&y,&z);
         a[i][0]=y;
         a[i][1]=z;
         a[i][2]=b[x];
         b[x]=i;
         a[i+n][0]=x;
         a[i+n][1]=z;
         a[i+n][2]=b[y];
         b[y]=i+n;
      }
      dep[0]=0;
      floodfill(1,0);
      memset(f,-1,sizeof(f));
      memset(g,-1,sizeof(g));
      memset(dist,-1,sizeof(dist));
      printf("%d\n",count(1));
   }
   system("pause");
   return(0);
}
int m=0;
void floodfill(int x,int father)
{
   dep[x]=dep[father]+1;
   in[x]=++m;
   fa[x]=father;
   for (int i=b[x];i;i=a[i][2])
   {
      if (a[i][0]==father)
         continue;
      floodfill(a[i][0],x);
      v[a[i][0]]=a[i][1];
   }
   out[x]=++m;
}
int count(int x)
{
   bool check(int,int);
   int get(int,int);
   if (g[x]!=-1)
      return(g[x]);
   g[x]=inf;
   for (int i=1;i<=n;i++)
   {
      if (!check(i,x))
         continue;
      int p=get(x,i);
      if (p<g[x])
         g[x]=p;
   }
   return(g[x]);
}
int get(int x,int y)
{
   int get_dist(int,int),count(int);
   bool check(int,int);
   if (f[x][y]!=-1)
      return(f[x][y]);
   f[x][y]=inf;
   if (get_dist(x,y)>d[x])
      return(f[x][y]);
   f[x][y]=0;
   if (!check(y,x))
   {
      for (int i=b[x];i;i=a[i][2])
      {
         if (a[i][0]==fa[x])
            continue;
         int p=count(a[i][0]),q=get(a[i][0],y);
         if (p>q)
            p=q;
         f[x][y]+=p;
      }
      return(f[x][y]);
   }
   if (x==y)
   {
      for (int i=b[x];i;i=a[i][2])
      {
         if (a[i][0]==fa[x])
            continue;
         int p=count(a[i][0]),q=get(a[i][0],y);
         if (p>q)
            p=q;
         f[x][y]+=p;
      }
      f[x][y]+=w[x];
      return(f[x][y]);
   }
   int t;
   for (int i=b[x];i;i=a[i][2])
   {
      if (a[i][0]==fa[x])
         continue;
      if (check(y,a[i][0]))
         t=get(a[i][0],y);
      else
      {
         int p=count(a[i][0]),q=get(a[i][0],y);
         if (p>q)
            p=q;
         f[x][y]+=p;
      }
   }
   f[x][y]+=t;
   return(f[x][y]);
}
int get_dist(int x,int y)
{
   if (dist[x][y]!=-1)
      return(dist[x][y]);
   if (x==y)
      dist[x][y]=0;
   else if (dep[x]>dep[y])
      dist[x][y]=get_dist(fa[x],y)+v[x];
   else
      dist[x][y]=get_dist(x,fa[y])+v[y];
   return(dist[x][y]);
}
bool check(int x,int y)
{
   if (in[x]>=in[y] && out[x]<=out[y])
      return(true);
   return(false);
}
