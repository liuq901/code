#include <cstdio>
#include <cstdlib>
#include <cmath>
int main()
{
   int i,c,n,m,t;
   double p;
   scanf("%d",&c);
   p=(sqrt(5)+3)/2;
   for (i=1;i<=c;i++)
   {
      scanf("%d%d",&m,&n);
      t=(int)(n/p);
      if ((m>=n-t && m<=n-1) || (m>=n+1 && m<=2*n-t-1))
         printf("Ollie wins\n");
      else
         printf("Stan wins\n");
   }
   system("pause");
   return(0);
}
