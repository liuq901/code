#include <cstdio>
#include <cstdlib>
int main()
{
   int n,i,k;
   double x[10001],y[10001];
   scanf("%d",&n);
   for (i=1;i<=n;i++)
      scanf("%lf%lf",&x[i],&y[i]);
   x[0]=y[0]=0;
   k=-1;
   for (i=1;i<=n;i++)
   {
      k*=-1;
      x[0]+=x[i]*k;
      y[0]+=y[i]*k;
   }
   if (n%2==0 && (x[0]!=0 || y[0]!=0))
      printf("NO\n");
   else
   {
      printf("YES\n");
      if (n%2==0 && x[0]==0 && y[0]==0)
         x[0]=y[0]=0.5;
      printf("%.3lf %.3lf\n",x[0],y[0]);
      for (i=1;i<n;i++)
      {
         x[i]=x[i]*2-x[i-1];
         y[i]=y[i]*2-y[i-1];
         printf("%.3lf %.3lf\n",x[i],y[i]);
      }
   }
   system("pause");
   return(0);
}
