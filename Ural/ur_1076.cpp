#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,b[151],dx[151],dy[151],slack[151],a[151][151];
bool f[151],g[151];
int main()
{
   bool hungary(int);
   int ans=0;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
      {
         scanf("%d",&a[i][j]);
         if (a[i][j]>dx[i])
            dx[i]=a[i][j];
         ans+=a[i][j];
      }
   for (int i=1;i<=n;i++)
   {
      memset(slack,26,sizeof(slack));
      memset(f,0,sizeof(f));
      memset(g,0,sizeof(g));
      while (!hungary(i))
      {
         int d=1<<30;
         for (int i=1;i<=n;i++)
            if (!g[i] && slack[i]<d)
               d=slack[i];
         for (int i=1;i<=n;i++)
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
      ans-=a[b[i]][i];
   printf("%d\n",ans);
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
      int t=dx[x]+dy[i]-a[x][i];
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
