#include <cstdio>
#include <cstdlib>
#include <cmath>
int main()
{
   int i,n,t,flag;
   scanf("%d",&n);
   flag=0;
   t=(int)sqrt(n)+100;
   for (i=2;i<=t;i++)
      if (n%(i+1)==0)
      {
         printf("%d\n",i);
         flag=1;
         break;
      }
   if (!flag && n%2==1)
      printf("%d\n",n-1);
   if (!flag && n%2==0)
      printf("%d\n",n/2-1);
   system("pause");
   return(0);
}
