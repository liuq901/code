#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SQR(x) ((x)*(x))
using namespace std;
int main()
{
   for (int i=1;i<=1000;i++)
      for (int j=i;j<=1000-i;j++)
      {
         int k=1000-i-j;
         if (SQR(i)+SQR(j)==SQR(k))
            printf("%d\n",i*j*k);
      }
   system("pause");
   return(0);
}
