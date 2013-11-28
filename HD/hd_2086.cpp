#include <cstdio>
#include <cstdlib>
int main()
{
   int n;
   while (scanf("%d",&n)==1)
   {
      double a,b;
      scanf("%lf%lf",&a,&b);
      double *c=new(double[n+10]);
      for (int i=1;i<=n;i++)
         scanf("%lf",&c[i]);
      double ans=a*n+b;
      for (int i=1;i<=n;i++)
         ans-=(i<<1)*c[n-i+1];
      printf("%.2f\n",ans/(n+1));
      delete[](c);
   }
   system("pause");
   return(0);
}
