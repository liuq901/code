#include <cstdio>
#include <cstdlib>
#include <cmath>
const double R=8.314;
const int inf=(1<<30)-1;
int main()
{
   int p,V,n,T;
   p=V=n=T=inf;
   for (int i=1;i<=3;i++)
   {
      char s[10];
      int x;
      scanf("%s %*s %d",s,&x);
      if (s[0]=='p')
         p=x;
      else if (s[0]=='V')
         V=x;
      else if (s[0]=='n')
         n=x;
      else if (s[0]=='T')
         T=x;
   }
   if (V==inf)
      if (n==0 && p!=0 || n!=0 && p==0)
         printf("error\n");
      else if (n==0 && p==0)
         printf("undefined\n");
      else
         printf("V = %f\n",n*R*T/p);
   if (n==inf)
      printf("n = %f\n",p/R*V/T);
   if (p==inf)
      printf("p = %f\n",n*R*T/V);
   if (T==inf)
      if (p==0 && n==0)
         printf("undefined\n");
      else if (p==0 && n!=0 || p!=0 && n==0)
         printf("error\n");
      else
         printf("T = %f\n",p/R*V/n);
   system("pause");
   return(0);
}
