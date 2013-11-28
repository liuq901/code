#include <cstdio>
#include <cstdlib>
#include <cmath>
int main()
{
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      double a,b,c,l,m,n;      
      scanf("%lf%lf%lf%lf%lf%lf",&l,&n,&a,&m,&b,&c);
      double x,y,v;
      x=4*a*a*b*b*c*c-a*a*(b*b+c*c-m*m)*(b*b+c*c-m*m)-b*b*(c*c+a*a-n*n)*(c*c+a*a-n*n);
      y=c*c*(a*a+b*b-l*l)*(a*a+b*b-l*l)-(a*a+b*b-l*l)*(b*b+c*c-m*m)*(c*c+a*a-n*n);
      v=pow(x-y,0.50000);
      printf("%.4lf\n",v/12);
   }
   system("pause");
   return(0);
}
