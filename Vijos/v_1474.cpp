#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int i,j,n,x,a[2][2501],f[2501];
   scanf("%d",&n);
   for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
      {
         scanf("%d",&x);
         a[0][x]=i;
         a[1][x]=j;
      }
   memset(f,0,sizeof(f));
   for (i=n*n;i>=1;i--)
      for (j=n*n;j>i;j--)
      {
         x=abs(a[0][i]-a[0][j])+abs(a[1][i]-a[1][j]);
         x*=x;
         if (f[j]+x>f[i])
            f[i]=f[j]+x;
      }
   printf("%d\n",f[1]);
   system("pause");
   return(0);
}
