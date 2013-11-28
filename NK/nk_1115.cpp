#include <cstdio>
#include <cstdlib>
long long a[90];
int main()
{
   a[1]=a[2]=1;
   for (int i=3;i<=80;i++)
      a[i]=a[i-1]+a[i-2];
   int n;
   while (scanf("%d",&n)==1)
      printf("%lld\n",a[n]);
   system("pause");
   return(0);
}
