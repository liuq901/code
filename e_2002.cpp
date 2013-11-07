#include <cstdio>
#include <cstdlib>
#include <cmath>
int main()
{
   int a,b;
   while (scanf("%d%d",&a,&b)==2)
      printf("%.3f\n",sqrt(a*a+b*b));
   system("pause");
   return(0);
}
