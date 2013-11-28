#include <cstdio>
#include <cstdlib>
int main()
{
   int gcd(int,int);
   int a,b;
   while (scanf("%d%d",&a,&b)==2)
   {
      int t=gcd(a,b);
      printf("%d\n",a/t*b);
   }
   system("pause");
   return(0);
}
int gcd(int a,int b)
{
   return(b?gcd(b,a%b):a);
}
