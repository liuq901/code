#include <cstdio>
#include <cstdlib>
#include <cmath>
const double eps=1e-8;
int main()
{
   bool check(int);
   int ans=0;
   for (int i=10;i<=200000;i++)
      ans+=i*check(i);
   printf("%d\n",ans);
   system("pause");
   return(0);
}
bool check(int x)
{
   int t=x,sum=0;
   while (t)
   {
      int p=t%10;
      sum+=int(pow(p,5)+eps);
      t/=10;
   }
   return(sum==x);
}
