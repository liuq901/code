#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int min(int,int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n,a[101][101];
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
         for (int j=1;j<=i;j++)
            scanf("%d",&a[i][j]);
      int f[101][101];
      f[0][1]=0;
      for (int i=1;i<=n;i++)
      {
         f[i][1]=f[i-1][1]+a[i][1];
         f[i][i]=f[i-1][i-1]+a[i][i];
         for (int j=2;j<i;j++)
            f[i][j]=min(f[i-1][j-1],f[i-1][j])+a[i][j];
      }
      int ans=0x7FFFFFFF;
      for (int i=1;i<=n;i++)
         if (f[n][i]<ans)
            ans=f[n][i];
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
int min(int x,int y)
{
   return(x<y?x:y);
}
