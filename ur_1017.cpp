#include <cstdio>
#include <cstdlib>
long long f[501];
int main()
{
   f[0]=1;
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      for (int j=n;j>=i;j--)
         f[j]+=f[j-i];
   printf("%I64d\n",f[n]-1);
   system("pause");
   return(0);
}
