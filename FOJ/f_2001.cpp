#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll inf=1LL<<60;
int n,S;
ll a[310][310];
bool f[310];
int main()
{
   ll cut();
   while (1)
   {
      int m;
      scanf("%d%d%d",&n,&m,&S);
      if (!n && !m && !S)
         break;
      memset(a,0,sizeof(a));
      while (m--)
      {
         int x,y,z;
         scanf("%d%d%d",&x,&y,&z);
         a[x][y]+=z,a[y][x]+=z;
      }
      ll ans=inf;
      memset(f,0,sizeof(f));
      for (int i=1;i<n;i++)
         ans=min(ans,cut());
      printf("%I64d\n",ans);
   }
   system("pause");
   return(0);
}
int t,T;
ll cut()
{
   ll calc();
   ll ret=calc();
   if (ret!=inf)
   {
      f[T]=true;
      for (int i=1;i<=n;i++)
         if (!f[i])
            a[i][t]+=a[i][T],a[t][i]+=a[T][i];
   }
   return(ret);
}
bool vis[310];
ll cost[310];
ll calc()
{
   memset(vis,0,sizeof(vis));
   memset(cost,0,sizeof(cost));
   cost[0]=-inf;
   cost[S]=inf;
   t=T=-1;
   for (int i=1;i<=n;i++)
   {
      int k=0;
      for (int j=1;j<=n;j++)
         if (!f[j] && !vis[j] && cost[j]>cost[k])
            k=j;
      if (!k)
         break;
      vis[k]=true;
      t=T,T=k;
      for (int j=1;j<=n;j++)
         if (!f[j] && !vis[j])
            cost[j]+=a[k][j];
   }
   return(t==-1?inf:cost[T]);
}
