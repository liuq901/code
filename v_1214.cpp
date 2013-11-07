#include <cstdio>
#include <cstdlib>
#include <cmath>
int main()
{
   void work(int);
   int n;
   while (1)
   {
      scanf("%d",&n);
      if (n==0)
         break;
      work(n);
   }
   system("pause");
   return(0);
}
void work(int n)
{
   double s;
   int i,x;
   long long d,f,ans1,ans2;
   ans1=ans2=0;
   f=n;
   s=sqrt(n);
   for (i=2;i<=s;i++)
   {
      d=n/i;
      ans1+=(f-d)*(i-1);
      ans2+=n*(f-d)-(d+f+1)*(f-d)/2*(i-1);
      f=d;
   }
   x=n/(int)s;
   for (i=1;i<=x;i++)
   {
      ans1+=n/i;
      ans2+=n%i;
   }
   printf("%I64d %I64d\n",ans1,ans2);
}
