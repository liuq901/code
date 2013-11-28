#include <cstdio>
#include <cstdlib>
#define SQR(x) ((x)*(x))
int main()
{
   int sum=0,tot=0;
   for (int i=1;i<=100;i++)
   {
      sum+=SQR(i);
      tot+=i;
   }
   printf("%d\n",SQR(tot)-sum);
   system("pause");
   return(0);
}
