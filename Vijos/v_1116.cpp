#include <cstdio>
#include <cstdlib>
#include <cmath>
double a,b,c,d,x,p,q;
double anx[3]={0};
int i,t;
int main()
{
   double f(double),findx(int);
   scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
   t=-1;
   for (i=-100;i<=100;i++)
   {
      if (fabs(f(i))<1e-6 || f(i)*f(i+1-1e-6)<=0)
      {
         t++;
         anx[t]=findx(i);
      }
   }
   for (t=0;t<2;t++)
      printf("%.2lf ",anx[t]);
   printf("%.2lf\n",anx[2]);
   system("pause");
   return(0);
}
double f(double x)
{
   double ans;
   ans=((a*x+b)*x+c)*x+d;
   return(ans);
}
double findx(int i)
{
   p=i;
   q=p+1-1e-6;
   if (fabs(f(p))<=1e-6)
      return(p);
   else
   {
      while (p+1e-6<q && f((p+q)/2.0)!=0)
         if (f(p)*f((p+q)/2)<0)
            q=(p+q)/2;
         else
            p=(p+q)/2;
      return((p+q)/2);
   }
}
