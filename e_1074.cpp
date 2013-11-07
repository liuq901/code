#include <cstdio>
#include <cstdlib>
#include <cmath>
int main()
{
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      int t,k;
      t=int(n*log10(n));
      k=int(pow(10,n*log10(n)-t));
      printf("%d\n",k);
   }
   system("pause");
   return(0);
}
