#include <cstdio>
#include <cstdlib>
int f[2002][2001];
int main()
{
   int max(int,int);
   int n,a[2001];
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%d",&a[i]);
   for (int i=n;i>=1;i--)
      for (int j=i;j<=n;j++)
      {
         int t=n+i-j;
         f[i][j]=max(f[i+1][j]+a[i]*t,f[i][j-1]+a[j]*t);
      }
   printf("%d\n",f[1][n]);
   system("pause");
   return(0);
}
int max(int x,int y)
{
   return(x>y?x:y);
}
