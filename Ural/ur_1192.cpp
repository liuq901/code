#include <cstdio>
#include <cstdlib>
#include <cmath>
const int g=10;
const double pi=3.1415926535897;
int main()
{
   int v,a;
   double k;
   scanf("%d%d%lf",&v,&a,&k);
   printf("%.2lf\n",v*v*sin(a*pi/90)/g/(1-1/k));
   system("pause");
   return(0);
}
