#include <cstdio>
#include <cstdlib>
int main()
{
   int gcd(int,int);
   int n,m;
   scanf("%d%d",&n,&m);
   n--;
   m--;
   printf("%d\n",n+m-gcd(n,m));
   system("pause");
   return(0);
}
int gcd(int a,int b)
{
   if (b==0)
      return(a);
   return(gcd(b,a%b));
}
