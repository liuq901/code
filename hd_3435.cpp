#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
int n,b[1010],dx[1010],dy[1010],slack[1010],a[1010][1010];
bool f[1010],g[1010];
int main()
{
   bool hungary(int);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int m;
      scanf("%d%d",&n,&m);
      memset(a,-63,sizeof(a));
      for (int i=1;i<=m;i++)
      {
         int x,y,z;
         scanf("%d%d%d",&x,&y,&z);
         a[x][y]=max(a[x][y],-z);
         a[y][x]=max(a[y][x],-z);
      }
      memset(b,0,sizeof(b));
      memset(dx,-63,sizeof(dx));
      memset(dy,0,sizeof(dy));
      for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
            dx[i]=max(dx[i],a[i][j]);
      for (int i=1;i<=n;i++)
      {
         memset(slack,63,sizeof(slack));
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
      bool flag=true;
      int ans=0;
      for (int i=1;i<=n;i++)
      {
         int t=a[b[i]][i];
         if (t<-1000000000)
         {
            flag=false;
            break;
         }
         ans+=-t;
      }
      static int id=0;
      printf("Case %d: ",++id);
      if (!flag)
         printf("NO\n");
      else
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
      else
         slack[i]=min(slack[i],t);
   }
   return(false);
}
