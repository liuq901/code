#include <cstdio>
#include <cstdlib>
int main()
{
   long long f[50];
   f[1]=f[2]=2;
   int n;
   scanf("%d",&n);
   for (int i=3;i<=n;i++)
      f[i]=f[i-2]+f[i-1];
   printf("%I64d\n",f[n]);
   system("pause");
   return(0);
}
