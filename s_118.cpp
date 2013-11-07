#include <cstdio>
#include <cstdlib>
int main()
{
   int i,j,k,n,m,sum,ans;
   int a[1001];
   scanf("%d",&n);
   for (i=1;i<=n;i++)
   {
      scanf("%d",&m);
      for (j=1;j<=m;j++)
      {
         scanf("%d",&a[j]);
         a[j]%=9;
      }
      ans=0;
      sum=1;
      for (j=1;j<=m;j++)
      {
         sum=sum*a[j]%9;
         ans=(ans+sum)%9;
      }
      printf("%d\n",(ans+8)%9+1);
   }
   system("pause");
   return(0);
}
