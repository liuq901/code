#include <cstdio>
#include <cstdlib>
#include <cstring>
int a[1001][1001];
int main()
{
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int p,n,m;
      scanf("%d%d%d",&p,&n,&m);
      memset(a,26,sizeof(a));
      for (int i=1;i<=m;i++)
      {
         int x,y,z;
         scanf("%d%d%d",&x,&y,&z);
         if (z<a[x][y])
            a[x][y]=a[y][x]=z;
      }
      bool flag[1001]={0};
      int cost[1001],ans=0;
      memset(cost,26,sizeof(cost));
      cost[1]=0;
      for (int i=1;i<=n;i++)
      {
         int k=0;
         for (int j=1;j<=n;j++)
            if (!flag[j] && cost[j]<cost[k])
               k=j;
         flag[k]=true;
         ans+=cost[k];
         for (int j=1;j<=n;j++)
            if (a[k][j]<cost[j])
               cost[j]=a[k][j];
      }
      printf("%d\n",ans*p);
   }
   system("pause");
   return(0);
}
