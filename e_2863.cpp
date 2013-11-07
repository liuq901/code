#include <cstdio>
#include <cstdlib>
#include <cmath>
const double g=9.8;
int main()
{
   int n;
   scanf("%d",&n);
   double h=1.75;
   for (int i=4;i<=n;i++)
      h+=3;
   if (n>=3)
      h+=5;
   if (n>=2)
      h+=5;
   printf("%.3f\n",sqrt(h*2/g));
   system("pause");
   return(0);
}
