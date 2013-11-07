#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int inf=1000000000;
int n,b[210],slack[210],dx[210],dy[210],a[210][210];
bool f[210],g[210];
int main()
{
   bool hungary(int);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int m;
      scanf("%d%d",&n,&m);
      for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
            a[i][j]=-inf;
      memset(dy,0,sizeof(dy));
      memset(dx,-63,sizeof(dx));
      for (int i=1;i<=m;i++)
      {
         int x,y,z;
         scanf("%d%d%d",&x,&y,&z);
         a[x][y]=-z;
         dx[x]=max(dx[x],-z);
      }
      memset(b,0,sizeof(b));
      for (int i=1;i<=n;i++)
      {
         memset(slack,63,sizeof(slack));
         while (1)
         {
            memset(f,0,sizeof(f));
            memset(g,0,sizeof(g));
            if (hungary(i))
               break;
            int d=inf;
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
         }
      }
      ll ans=0;
      for (int i=1;i<=n;i++)
      {
         if (a[b[i]][i]==-inf)
         {
            ans=1;
            break;
         }
         ans+=a[b[i]][i];
      }
      if (ans==1)
         printf("Impossible\n");
      else
         printf("%lld\n",-ans);
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
      else if (t<slack[i])
         slack[i]=t;
   }
   return(false);
}
