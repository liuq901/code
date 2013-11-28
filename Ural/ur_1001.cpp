#include <cstdio>
#include <cstdlib>
#include <cmath>
double a[1000000];
int main()
{
   int i,s;
   double k;
   s=0;
   while (scanf("%lf",&k)!=EOF)
   {
      s++;
      a[s]=sqrt(k);  
   }
   for (i=s;i>=1;i--)
      printf("%.4lf\n",a[i]);
   system("pause");
   return(0);
}
