#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,dx[101],dy[101],slack[101],b[101],a[101][101];
bool f[101],g[101];
int main()
{
   bool hungary(int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int c1,c2;
      scanf("%d%d",&c1,&c2);
      n=c1>c2?c1:c2;
      memset(a,0,sizeof(a));
      memset(b,0,sizeof(b));
      memset(dx,0,sizeof(dx));
      memset(dy,0,sizeof(dy));
      while (1)
      {
         int x,y,z;
         scanf("%d%d%d",&x,&y,&z);
         if (!x && !y && !z)
            break;
         a[x][y]=z;
         if (a[x][y]>dx[x])
            dx[x]=a[x][y];
      }
      for (int i=1;i<=n;i++)
      {
         memset(f,0,sizeof(f));
         memset(g,0,sizeof(g));
         memset(slack,26,sizeof(slack));
         while (1)
         {
            if (hungary(i))
               break;
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
      int ans=0;
      for (int i=1;i<=n;i++)
         ans+=a[b[i]][i];
      printf("%d\n",ans);
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
      int d=dx[x]+dy[i]-a[x][i];
      if (!d)
      {
         g[i]=true;
         if (hungary(b[i]))
         {
            b[i]=x;
            return(true);
         }
      }
      else if (d<slack[i])
         slack[i]=d;
   }
   return(false);
}
