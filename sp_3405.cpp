#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf=1061109567;
int n,d[510],c[510],a[510][510],b[510][510];
int main()
{
   void dijkstra(int,int *);
   while (1)
   {
      int m;
      scanf("%d%d",&n,&m);
      if (!n && !m)
         break;
      memset(a,63,sizeof(a));
      int S,T;
      scanf("%d%d",&S,&T);
      for (int i=1;i<=m;i++)
      {
         int x,y,z;
         scanf("%d%d%d",&x,&y,&z);
         a[x][y]=z;
      }
      dijkstra(S,d);
      for (int i=0;i<n;i++)
         for (int j=i;j<n;j++)
            swap(a[i][j],a[j][i]);
      dijkstra(T,c);
      for (int i=0;i<n;i++)
         for (int j=i;j<n;j++)
            swap(a[i][j],a[j][i]);
      for (int i=0;i<n;i++)
         for (int j=0;j<n;j++)
            if (d[i]+a[i][j]+c[j]==d[T])
               a[i][j]=inf;
      dijkstra(S,d);
      if (d[T]==inf)
         d[T]=-1;
      printf("%d\n",d[T]);
   }
   system("pause");
   return(0);
}
bool vis[510];
void dijkstra(int S,int *d)
{
   memset(vis,0,sizeof(vis));
   for (int i=0;i<=n;i++)
      d[i]=inf;
   d[S]=0;
   for (int i=1;i<=n;i++)
   {
      int k=n;
      for (int j=0;j<n;j++)
         if (!vis[j] && d[j]<d[k])
            k=j;
      if (k==n)
         break;
      vis[k]=true;
      for (int j=0;j<n;j++)
         if (!vis[j] && d[k]+a[k][j]<d[j])
            d[j]=d[k]+a[k][j];
   }
}
