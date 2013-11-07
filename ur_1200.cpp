#include <cstdio>
#include <cstdlib>
int main()
{
   double a,b;
   int n,x,y;
   scanf("%lf%lf%d",&a,&b,&n);
   if (a<0)
      a=0;
   if (b<0)
      b=0;
   x=(a/2-int(a/2))>0.5?int(a/2)+1:int(a/2);
   y=(b/2-int(b/2))>0.5?int(b/2)+1:int(b/2);
   if (x+y>n)
   {
      double t=(a-b+2*n)/4;
      x=t-int(t)>0.5?int(t)+1:int(t);
      if (x>n)
         x=n;
      if (x<0)
         x=0;
      y=n-x;
   }
   printf("%.2lf\n%d %d\n",a*x+b*y-x*x-y*y,x,y);
   system("pause");
   return(0);
}
