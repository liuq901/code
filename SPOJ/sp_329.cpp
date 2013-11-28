#include <cstdio>
#include <cstdlib>
int a[301][301];
int main()
{
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n,k;
      scanf("%d%d",&n,&k);
      for (int i=1;i<=n;i++)
         for (int j=i+1;j<=n;j++)
         {
            scanf("%d",&a[i][j]);
            a[j][i]=a[i][j];
         }
      int sum=n*(n-1)/2;
      for (int i=1;i<=n;i++)
         for (int j=i+1;j<=n;j++)
            for (int k=1;k<=n;k++)
            {
               if (k==i || k==j)
                  continue;
               if (a[i][k]+a[k][j]==a[i][j])
               {
                  sum--;
                  break;
               }
            }
      printf("%s\n",sum<=k?"YES":"NO");
   }
   system("pause");
   return(0);
}
