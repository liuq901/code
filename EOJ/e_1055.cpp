#include <cstdio>
#include <cstdlib>
int main()
{
   int gcd(int,int);
   int n,m;
   while (scanf("%d%d",&n,&m)!=EOF)
      printf("%d\n",gcd(n,m));
   system("pause");
   return(0);
}
int gcd(int a,int b)
{
   return(b?gcd(b,a%b):a);
}
