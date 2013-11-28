#include <cstdio>
#include <cstdlib>
int main()
{
   int n,i;
   long long a[20];
   scanf("%d",&n);
   a[0]=1;
   for (i=1;i<=n;i++)
      a[i]=2*(2*i-1)*a[i-1]/(i+1);
   printf("%I64d\n",a[n]);
   system("pause");
   return(0);
}
