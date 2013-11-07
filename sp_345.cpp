#include <cstdio>
#include <cstdlib>
int main()
{
   int min(int,int),get(int,int);
   int n;
   while (scanf("%d",&n)!=EOF)
   {
      int a[101],s[101];
      for (int i=1;i<=n;i++)
      {
         scanf("%d",&a[i]);
         s[i]=s[i-1]+a[i];
      }
      int b[101][101],f[101][101];
      for (int i=1;i<=n;i++)
         for (int j=i;j<=n;j++)
            b[i][j]=(s[j]-s[i-1])%100;
      for (int i=n;i>=1;i--)
         for (int j=i;j<=n;j++)
         {
            if (i==j)
            {
               f[i][j]=0;
               continue;
            }
            f[i][j]=1<<30;
            for (int k=i;k<j;k++)
               f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+b[i][k]*b[k+1][j]);
         }
      printf("%d\n",f[1][n]);
   }
   system("pause");
   return(0);
}
int min(int x,int y)
{
   return(x<y?x:y);
}
