#include <cstdio>
#include <cstdlib>
int main()
{
   int i,n;
   long long f[70000];
   scanf("%d",&n);
   f[0]=1;
   for (i=1;i<=n;i++)
      f[i]=f[i-1]+i;
   printf("%I64d\n",f[n]);
   system("pause");
   return(0);
}
