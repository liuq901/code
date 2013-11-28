#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps=1e-8;
int main()
{
   bool check(int,int);
   int p=1,q=1;
   for (int i=10;i<100;i++)
      for (int j=i+1;j<100;j++)
         if (check(i,j))
            p*=i,q*=j;
   int t=__gcd(p,q);
   printf("%d\n",q/t);
   system("pause");
   return(0);
}
bool check(int a,int b)
{
   if (a/10==a%10 || b/10==b%10)
      return(false);
   if (!(a%10) || !(b%10))
      return(false);
   if (a/10==b%10)
   {
      int x=a%10,y=b/10;
      if (fabs(double(a)/b-double(x)/y)<eps)
         return(true);
   }
   if (a%10==b%10)
   {
      int x=a/10,y=b/10;
      if (fabs(double(a)/b-double(x)/y)<eps)
         return(true);
   }
   if (a/10==b/10)
   {
      int x=a%10,y=b%10;
      if (fabs(double(a)/b-double(x)/y)<eps)
         return(true);
   }
   if (a%10==b/10)
   {
      int x=a/10,y=b%10;
      if (fabs(double(a)/b-double(x)/y)<eps)
         return(true);
   }
   return(false);
}
