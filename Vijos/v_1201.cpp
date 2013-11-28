#include <cstdio>
#include <cstdlib>
int main()
{
   long long m,n,t;
   int i,j,a[32];
   scanf("%I64d",&m);
   for (i=0;i<32;i++)
   {
      a[i]=m%2;
      m/=2;
   }
   n=0;
   for (i=0;i<=15;i++)
   {
      if (a[i]==1)
      {
         t=1;
         for (j=1;j<=i+16;j++)
            t*=2;
         n+=t;
      }
   }
   for (i=16;i<=31;i++)
   {
      if (a[i]==1)
      {
         t=1;
         for (j=1;j<=i-16;j++)
            t*=2;
         n+=t;
      }
   }
   printf("%I64d\n",n);
   system("pause");
   return(0);
}
