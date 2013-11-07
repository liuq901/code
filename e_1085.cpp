#include <cstdio>
#include <cstdlib>
int a[110][110];
int main()
{
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (n<=0)
         break;
      int t=0;
      for (int i=1;i<=n;i++)
         for (int j=1;j<=i;j++)
            a[i-j+1][j]=++t;
      static int id=0;
      if (id)
         printf("\n");
      printf("Case %d:\n",++id);
      for (int i=1;i<=n;i++)
         for (int j=1;j<=n-i+1;j++)
            printf("%d%c",a[i][j],j==n-i+1?'\n':' ');
   }
   system("pause");
   return(0);
}
