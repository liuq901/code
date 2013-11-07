#include <cstdio>
#include <cstdlib>
int main()
{
   long long m;
   int n;
   scanf("%d",&n);
   if (n%2==0)
   {
      m=n/2;
      m*=(n+1);
      m+=1;
   }
   else
   {
      m=(n+1)/2;
      m*=n;
      m+=1;
   }
   printf("%I64d\n",m);
   system("pause");
   return(0);
}
