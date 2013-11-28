#include <cstdio>
#include <cstdlib>
int main()
{
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n;
      scanf("%d",&n);
      int a[51];
      long long f[51][51];
      for (int i=1;i<=n;i++)
         scanf("%d%d",&a[i-1],&a[i]);
      for (int j=1;j<=n;j++)
         for (int i=j;i>=1;i--)
         {
            if (i==j)
            {
               f[i][j]=0;
               continue;
            }
            f[i][j]=1LL<<60;
            for (int k=i;k<=j-1;k++)
            {
               long long p=f[i][k]+f[k+1][j]+(long long)a[i-1]*a[k]*a[j];
               if (p<f[i][j])
                  f[i][j]=p;
            }
         }
      printf("%I64d\n",f[1][n]);
   }
   system("pause");
   return(0);
}
