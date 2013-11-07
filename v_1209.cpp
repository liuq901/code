#include <cstdio>
#include <cstdlib>
int main()
{
   int check(int,int);
   int i,k,n,m;
   int a[26];
   scanf("%d",&k);
   for (i=1;i<=k;i++)
   {
      scanf("%d%d",&n,&m);
      a[i]=check(n,m);
   }
   for (i=1;i<=k;i++)
      if (a[i])
         printf("y");
      else
         printf("n");
   printf("\n");
   system("pause");
   return(0);
}
int check(int n,int m)
{
   int gcd(int,int);
   if (n==0 || m==0)
      if (n==1 || m==1)
         return(1);
      else
         return(0);
   if ((n+m)%2==0)
      return(0);
   if (gcd(n,m)!=1)
      return(0);
   return(1);
}
int gcd(int a,int b)
{
   if (b==0)
      return(a);
   else
      return(gcd(b,a%b));
}
