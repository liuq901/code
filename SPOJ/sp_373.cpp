#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,dx[501],dy[501],slack[501],b[501],w[501][501];
bool f[501],g[501];
int main()
{
   bool hungary(int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int m,p[501],a[501][501];
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
         scanf("%d",&p[i]);
      memset(a,26,sizeof(a));
      scanf("%d",&m);
      for (int i=1;i<=m;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         a[x][y]=a[y][x]=1;
      }
      for (int i=1;i<=n;i++)
         a[i][i]=0;
      for (int k=1;k<=n;k++)
         for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
               if (a[i][k]+a[k][j]<a[i][j])
                  a[i][j]=a[i][k]+a[k][j];
      memset(dx,-26,sizeof(dx));
      memset(dy,0,sizeof(dy));
      for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
         {
            w[i][j]=-a[p[i]][j];
            if (w[i][j]>dx[i])
               dx[i]=w[i][j];
         }
      memset(b,0,sizeof(b));
      for (int i=1;i<=n;i++)
      {
         memset(slack,26,sizeof(slack));
         while (1)
         {
            memset(f,0,sizeof(f));
            memset(g,0,sizeof(g));
            if (hungary(i))
               break;
            int d=1<<30;
            for (int j=1;j<=n;j++)
               if (!g[j] && slack[j]<d)
                  d=slack[j];
            for (int j=1;j<=n;j++)
            {
               if (f[j])
                  dx[j]-=d;
               if (g[j])
                  dy[j]+=d;
            }
         }
      }
      int ans=0;
      for (int i=1;i<=n;i++)
         ans+=w[b[i]][i];
      printf("%d\n",-ans);
   }
   system("pause");
   return(0);
}
bool hungary(int x)
{
   if (!x)
      return(true);
   f[x]=true;
   for (int i=1;i<=n;i++)
   {
      if (g[i])
         continue;
      int t=dx[x]+dy[i]-w[x][i];
      if (!t)
      {
         g[i]=true;
         if (hungary(b[i]))
         {
            b[i]=x;
            return(true);
         }
      }
      else if (t<slack[i])
         slack[i]=t;
   }
   return(false);
}
