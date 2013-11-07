#include <cstdio>
#include <cstdlib>
int x,i,j,t,n,a[101][101];
int main()
{
   for (scanf("%d",&t);t;t--)
   {
      scanf("%d",&n);
      x=0;
      for (i=1;i<=n;i++)
         for (j=1;j<=i;j++)
         {
            scanf("%d",&a[i][j]);
            a[i][j]+=a[i-1][j]>?a[i-1][j-1];
            x>?=a[i][j];
         }
      printf("%d\n",x);
   }
   system("pause");
   return(0);
}
