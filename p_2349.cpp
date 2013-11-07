#include <cstdio>
#include <cstdlib>
#include <cmath>
int main()
{
   double dist(int,int,int,int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int p,n,x[501],y[501];
      double a[501][501];
      scanf("%d%d",&p,&n);
      for (int i=1;i<=n;i++)
         scanf("%d%d",&x[i],&y[i]);
      for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
            a[i][j]=dist(x[i],y[i],x[j],y[j]);
      double cost[501],ans[501];
      bool f[501]={0};
      for (int i=1;i<=n;i++)
         cost[i]=1e10;
      cost[1]=0;
      for (int i=1;i<=n;i++)
      {
         cost[0]=1e10;
         int k=0;
         for (int j=1;j<=n;j++)
            if (!f[j] && cost[j]<cost[k])
               k=j;
         f[k]=true;
         ans[i]=cost[k];
         for (int j=1;j<=n;j++)
            if (a[k][j]<cost[j])
               cost[j]=a[k][j];
      }
      for (int i=1;i<=n-1;i++)
         for (int j=i;j<=n;j++)
            if (ans[i]<ans[j])
            {
               double t;
               t=ans[i],ans[i]=ans[j],ans[j]=t;
            }
      printf("%.2lf\n",ans[p]);
   }
   system("pause");
   return(0);
}
double dist(int x1,int y1,int x2,int y2)
{
   return(sqrt(double((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))));
}
