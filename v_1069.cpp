#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
double a[1001][1001];
int main()
{
   int i,j,k,n;
   int flag[1001];
   double ans,min;
   double cost[1001],x[1001],y[1001];
   scanf("%d",&n);
   for (i=1;i<=n;i++)
      scanf("%lf%lf",&x[i],&y[i]);
   for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
         a[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
   memset(flag,0,sizeof(flag));
   ans=0;
   for (i=2;i<=n;i++)
      cost[i]=a[1][i];
   flag[1]=1;
   for (i=2;i<=n;i++)
   {
      k=0;
      min=200000000;
      for (j=1;j<=n;j++)
         if (!flag[j] && cost[j]<min)
         {
            min=cost[j];
            k=j;
         }
      for (j=1;j<=n;j++)
         if (a[k][j]<cost[j])
            cost[j]=a[k][j];
      flag[k]=1;
      ans+=min;
   }
   printf("%.3lf\n",ans);
   system("pause");
   return(0);
}
