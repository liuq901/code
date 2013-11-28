#include <cstdio>
#include <cstdlib>
#define SQR(x) ((x)*(x))
int main()
{
   for (int i=1;i<=1000;i++)
      for (int j=i;j<=1000;j++)
      {
         int k=1000-i-j;
         if (k<i || k<j)
            break;
         if (SQR(i)+SQR(j)==SQR(k))
            printf("%d\n",i*j*k);
      }
   system("pause");
   return(0);
}
