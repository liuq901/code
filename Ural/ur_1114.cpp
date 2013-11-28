#include <cstdio>
#include <cstdlib>
typedef unsigned long long int64;
int64 f[26][26][26];
int main()
{
   int n,a,b;
   scanf("%d%d%d",&n,&a,&b);
   a++,b++;
   f[0][1][1]=1;
   for (int i=1;i<=n;i++)
      for (int j=1;j<=a;j++)
         for (int k=1;k<=b;k++)
            f[i][j][k]=f[i][j-1][k]+f[i][j][k-1]-f[i][j-1][k-1]+f[i-1][j][k];
   int64 ans=0;
   for (int i=1;i<=a;i++)
      for (int j=1;j<=b;j++)
         ans+=f[n][i][j];
   printf("%I64u\n",ans);
   system("pause");
   return(0);
}
