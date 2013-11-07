#include <cstdio>
#include <cstdlib>
int main()
{
   int a[10000],i,n;
   scanf("%d",&n);
   a[0]=1;
   a[1]=1;
   for (i=2;i<n;i++)
      a[i]=(a[i-2]+a[i-1])%7654321;
   printf("%d\n",a[n-1]);
   system("pause");
   return(0);
}
