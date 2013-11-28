#include <cstdio>
#include <cstdlib>
#include <cmath>
const int a[9]={1,1,2,6,2,1,7,5,4};
int main()
{
   int n;
   while (scanf("%d",&n)!=EOF)
   {
      if (n<9)
      {
         printf("%d\n",a[n]);
         continue;
      }
      int t,k;
      t=int(n*log10(n/exp(1))+log10(sqrt(2*acos(-1)*n)));
      k=int(pow(10,log10(n/exp(1))*n+log10(sqrt(2*acos(-1)*n))-t));
      printf("%d\n",k);
   }
   system("pause");
   return(0);
}
