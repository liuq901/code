#include <cstdio>
#include <cstdlib>
const long long c[11]={1,1,2,6,24,120,720,5040,40320,362880,3628800};
int main()
{
   int n,k;
   scanf("%d%d",&n,&k);
   if (n<k)
      printf("0\n");
   else
      printf("%I64d\n",c[n]*c[n]/c[k]/c[n-k]/c[n-k]);
   system("pause");
   return(0);
}
