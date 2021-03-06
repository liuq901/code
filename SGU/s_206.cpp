#include <cstdio>
#include <cstdlib>
#include <cstring>
int sum,dx[401],dy[401],slack[401],link[401],w[401][401];
int dep[61],c[61],b[61],fa[61],p[61],v[401],a[121][2];
bool f[401],g[401];
int main()
{
   void floodfill(int,int),build(int,int,int,int);
   bool hungary(int);
   int n,m;
   scanf("%d%d",&n,&m);
   n--;
   m-=n;
   sum=n>m?n:m;
   for (int i=1;i<=n;i++)
   {
      int x,y;
      scanf("%d%d%d",&x,&y,&c[i]);
      a[2*i-1][0]=y;
      a[2*i-1][1]=b[x];
      b[x]=2*i-1;
      a[2*i][0]=x;
      a[2*i][1]=b[y];
      b[y]=2*i;
   }
   dep[1]=1;
   floodfill(1,0);
   for (int i=1;i<=m;i++)
   {
      int x,y;
      scanf("%d%d%d",&x,&y,&v[i]);
      build(x,y,v[i],i);
   }
   for (int i=1;i<=sum;i++)
      for (int j=1;j<=sum;j++)
         if (w[i][j]>dx[i])
            dx[i]=w[i][j];
   for (int i=1;i<=sum;i++)
   {
      memset(slack,26,sizeof(slack));
      memset(f,0,sizeof(f));
      memset(g,0,sizeof(g));
      while (!hungary(i))
      {
         int d=1<<30;
         for (int i=1;i<=sum;i++)
            if (!g[i] && slack[i]<d)
               d=slack[i];
         for (int i=1;i<=sum;i++)
         {
            if (f[i])
               dx[i]-=d;
            if (g[i])
               dy[i]+=d;
         }
         memset(f,0,sizeof(f));
         memset(g,0,sizeof(g));
      }
   }
   for (int i=1;i<=n;i++)
      printf("%d\n",c[i]-dx[i]);
   for (int i=1;i<=m;i++)
      printf("%d\n",v[i]+dy[i]);
   system("pause");
   return(0);
}
void floodfill(int x,int father)
{
   for (int i=b[x];i;i=a[i][1])
   {
      if (a[i][0]==father)
         continue;
      fa[a[i][0]]=x;
      p[a[i][0]]=i+1>>1;
      dep[a[i][0]]=dep[x]+1;
      floodfill(a[i][0],x);
   }
}
void build(int u,int v,int cost,int id)
{
   while (u!=v)
   {
      int x;
      if (dep[u]>dep[v])
      {
         x=p[u];
         u=fa[u];
      }
      else
      {
         x=p[v];
         v=fa[v];
      }
      if (c[x]>cost)
         w[x][id]=c[x]-cost;
   }
}
bool hungary(int x)
{
   if (!x)
      return(true);
   f[x]=true;
   for (int i=1;i<=sum;i++)
   {
      if (g[i])
         continue;
      int d=dx[x]+dy[i]-w[x][i];
      if (!d)
      {
         g[i]=true;
         if (hungary(link[i]))
         {
            link[i]=x;
            return(true);
         }
      }
      else if (d<slack[i])
         slack[i]=d;
   }
   return(false);
}
