#include <cstdio>
#include <cstdlib>
#include <cmath>
const double eps=1e-6;
double b[21],a[21][21];
int main()
{
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
         scanf("%lf",&a[i][j]);
   for (int i=1;i<=n;i++)
      scanf("%lf",&b[i]);
   for (int i=1;i<=n;i++)
   {
      int k;
      for (int j=i;j<=n;j++)
         if (fabs(a[j][i])>eps)
         {
            k=j;
            break;
         }
      double t;
      for (int j=1;j<=n;j++)
         t=a[k][j],a[k][j]=a[i][j],a[i][j]=t;
      t=b[k],b[k]=b[i],b[i]=t;
      for (int j=1;j<=n;j++)
      {
         if (i==j)
            continue;
         double p=a[j][i]/a[i][i];
         for (int k=1;k<=n;k++)
            a[j][k]-=a[i][k]*p;
         b[j]-=b[i]*p;
      }
   }
   for (int i=1;i<=n;i++)
      printf("%.2lf\n",b[i]/a[i][i]);
   system("pause");
   return(0);
}
