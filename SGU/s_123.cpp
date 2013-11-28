#include <cstdio>
#include <cstdlib>
int main()
{
   int n,i;
   long long s;
   long long f[41];
   f[1]=f[2]=1;
   s=0;
   scanf("%d",&n);
   for (i=1;i<=n;i++)
   {
      if (i>=3)
         f[i]=f[i-2]+f[i-1];
      s+=f[i];
   }
   printf("%I64d\n",s);
   system("pause");
   return(0);
}
