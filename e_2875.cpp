#include <cstdio>
#include <cstdlib>
#include <cmath>
#define SQR(x) ((x)*(x))
int main()
{
   int n,sum=0,a[110];
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      scanf("%*s%d",&a[i]);
      sum+=a[i];
   }
   double ave=double(sum)/n,tot=0;
   for (int i=1;i<=n;i++)
      tot+=SQR(a[i]-ave);
   printf("%.2f %.2f\n",ave,sqrt(tot/(n-1)));
   system("pause");
   return(0);
}
