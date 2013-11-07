#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,m,dx[201],dy[201],slack[201],a[201],b[201],c[201][201],w[201][201];
bool f[201],g[201];
int main()
{
   bool hungary(int);
   void push(int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      scanf("%d%d",&n,&m);
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      for (int i=1;i<=m;i++)
         scanf("%d",&b[i]);      
      memset(dx,-26,sizeof(dx));
      memset(dy,0,sizeof(dy));
      memset(c,0,sizeof(c));
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
         {
            scanf("%d",&w[i][j]);
            w[i][j]*=-1;
            if (w[i][j]>dx[i])
               dx[i]=w[i][j];
         }
      for (int i=1;i<=n;i++)
         while (1)
         {
            memset(slack,26,sizeof(slack));
            while (a[i])
            {
               memset(f,0,sizeof(f));
               memset(g,0,sizeof(g));
               if (hungary(i))
                  push(i);
               else
                  break;
            }
            if (!a[i])
               break;
            int d=1<<30;
            for (int i=1;i<=m;i++)
               if (!g[i] && slack[i]<d)
                  d=slack[i];
            for (int i=1;i<=n;i++)
               if (f[i])
                  dx[i]-=d;
            for (int i=1;i<=m;i++)
               if (g[i])
                  dy[i]+=d;
         }
      int ans=0;
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
            ans+=c[i][j]*w[i][j];
      printf("%d\n",-ans);
   }
   system("pause");
   return(0);
}
int link[201],next[201];
bool hungary(int x)
{
   f[x]=true;
   for (int i=1;i<=m;i++)
   {
      if (g[i])
         continue;
      int d=dx[x]+dy[i]-w[x][i];
      if (!d)
      {
         g[i]=true;
         if (b[i])
         {
            link[x]=i;
            next[x]=0;
            return(true);
         }
         for (int j=1;j<=n;j++)
         {
            if (f[j])
               continue;
            if (c[j][i] && hungary(j))
            {
               link[x]=i;
               next[x]=j;
               return(true);
            }
         }
      }
      else if (d<slack[i])
         slack[i]=d;
   }
   return(false);
}
void push(int x)
{
   int d=a[x];
   for (int i=x;i;i=next[i])
   {
      if (next[i] && d>c[next[i]][link[i]])
         d=c[next[i]][link[i]];
      if (!next[i] && d>b[link[i]])
         d=b[link[i]];
   }
   a[x]-=d;
   for (int i=x;i;i=next[i])
   {
      if (next[i])
         c[next[i]][link[i]]-=d;
      else
         b[link[i]]-=d;
      c[i][link[i]]+=d;
   }
}
