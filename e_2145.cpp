#include <cstdio>
#include <cstdlib>
#define SQR(x) ((x)*(x))
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n,sum=0;
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
         sum+=(SQR(i)-SQR(i-1))*(n-i+1);
      printf("%d\n",sum<<2);
   }
   system("pause");
   return(0);
}
