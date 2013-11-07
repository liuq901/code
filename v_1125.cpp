#include <cstdio>
#include <cstdlib>
#include <cmath>
int main()
{
   double e=1e-5,g=10.0;
   double h,s1,v,l,k,t1,t2,vmin,vmax;
   int n1,n2,num,n;
   scanf("%lf%lf%lf%lf%lf%d",&h,&s1,&v,&l,&k,&n);
   num=-1;
   t1=sqrt(2*h/g);
   if (h<=k+e)
      t2=0;
   else
      t2=sqrt(2*(h-k-e)/g);
   if (s1-v*t2+l+e<0)
      num=0;
   else
      n2=(int)(s1-v*t2+l+e);
   if (n2>n-1)
      n2=n-1;
   if (s1-v*t1-e<=0)
      n1=0;
   else if (s1-v*t1-e>n-1)
      num=0;
   else if (s1-v*t1-e==(int)(s1-v*t1-e))
      n1=(int)(s1-v*t1-e);
   else
      n1=(int)(s1-v*t1-e)+1;
   if (num==-1)
      num=n2-n1+1;
   printf("%d\n",num);
   system("pause");
   return(0);
}
