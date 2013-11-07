#include <cstdio>
#include <cstdlib>
#include <cmath>
const double pi=3.1415926535897;
int n;
double a[101];
int main()
{
   bool check(),get(bool,double);
   double helen(double,double,double);
   double max,sum=0;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      scanf("%lf",&a[i]);
      sum+=a[i];
      if (a[i]>max)
      {
         max=a[i];
         double t;
         t=a[1],a[1]=a[i],a[i]=t;
      }
   }
   if (sum-a[1]<a[1])
      printf("0.00\n");
   else
   {
      bool flag=check();
      double l=max/2,r=2*sum;
      while (1)
      {
         if (fabs(l-r)<1e-6)
            break;
         double mid=(l+r)/2;
         if (get(flag,mid))
            l=mid;
         else
            r=mid;
      }
      sum=0;
      for (int i=1;i<=n;i++)
         sum+=helen(l,r,a[i]);
      if (!flag)
         sum-=2*helen(l,r,a[1]);
      printf("%.2lf\n",sum);
   }
   system("pause");
   return(0);
}
bool check()
{
   double sum=0,r=a[1]/2;
   for (int i=1;i<=n;i++)
      sum+=acos(1-((a[i]*a[i])/(2*r*r)));
   if (sum<2*pi)
      return(false);
   else
      return(true);
}
bool get(bool flag,double r)
{
   double sum=0;
   if (flag)
   {
      for (int i=1;i<=n;i++)
         sum+=acos(1-((a[i]*a[i])/(2*r*r)));
      if (sum>2*pi)
         return(true);
      else
         return(false);
   }
   else
   {
      for (int i=2;i<=n;i++)
         sum+=acos(1-((a[i]*a[i])/(2*r*r)));
      double theta=acos(1-((a[1]*a[1])/(2*r*r)));
      if (sum<theta)
         return(true);
      else
         return(false);
   }
}
double helen(double a,double b,double c)
{
   double p=(a+b+c)/2;
   return(sqrt(p*(p-a)*(p-b)*(p-c)));
}
