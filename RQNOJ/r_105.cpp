#include <cstdio>
#include <cstdlib>
int main()
{
   long long f[51];
   int n,m;
   scanf("%d%d",&n,&m);
   f[0]=1;
   for (int i=1;i<=n;i++)
      if (i<m)
         f[i]=f[i-1]<<1;
      else if (i==m)
         f[i]=(f[i-1]<<1)-1;
      else if (i>m)
         f[i]=(f[i-1]<<1)-f[i-m-1];
   printf("%I64d\n",f[n]);
   system("pause");
   return(0);
}
