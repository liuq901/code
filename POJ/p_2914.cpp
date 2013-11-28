#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf=1<<30;
int n,a[510][510];
bool f[510];
int main()
{
   int cut();
   int m;
   while (scanf("%d%d",&n,&m)==2)
   {
      memset(a,0,sizeof(a));
      while (m--)
      {
         int x,y,z;
         scanf("%d%d%d",&x,&y,&z);
         x++,y++;
         a[x][y]+=z,a[y][x]+=z;
      }
      int ans=inf;
      memset(f,0,sizeof(f));
      for (int i=1;i<n;i++)
         ans=min(ans,cut());
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
int t,T;
int cut()
{
   int calc();
   int ret=calc();
   if (T==-1)
      return(inf);
   f[T]=true;
   for (int i=1;i<=n;i++)
      if (!f[i])
         a[i][t]+=a[i][T],a[t][i]+=a[T][i];
   return(ret);
}
bool vis[510];
int cost[510];
int calc()
{
   memset(vis,0,sizeof(vis));
   memset(cost,0,sizeof(cost));
   cost[0]=-inf;
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
   return(cost[T]);
}
