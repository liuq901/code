#include <cstdio>
#include <cstdlib>
#define X 26
int main()
{
   int i,m,n;
   long long a[100]={0};
   scanf("%d%d",&n,&m);
   a[-1+X]=1;
   a[0+X]=1;
   for (i=1;i<=n;i++)
      a[i+X]=a[i-1+X]*2-a[i-m-1+X];
   printf("%I64d\n",a[n+X]);
   system("pause");
   return(0);
}
