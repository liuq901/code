#include <cstdio>
#include <cstdlib>
int main()
{
   int gcd(int,int);
   int n,i,s;
   scanf("%d",&n);
   s=0;
   for (i=1;i<=n;i++)
      if (gcd(n,i)==1)
         s++;
   printf("%d\n",s);
   system("pause");
   return(0);
}
int gcd(int a,int b)
{
   if (b==0)
      return(a);
   else
      return(gcd(b,a%b));
}
