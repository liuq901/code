#include <cstdio>
#include <cstdlib>
int f[1001][1001];
int main()
{
   int max(int,int);
   int n;
   while (scanf("%d",&n)!=EOF)
   {
      for (int i=1;i<=n;i++)
         for (int j=1;j<=i;j++)
         {
            int x;
            scanf("%d",&x);
            f[i][j]=max(f[i-1][j-1],f[i-1][j])+x;
         }
      int ans=0;
      for (int i=1;i<=n;i++)
         ans=max(ans,f[n][i]);
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
int max(int x,int y)
{
   return(x>y?x:y);
}
