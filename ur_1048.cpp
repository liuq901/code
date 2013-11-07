#include <cstdio>
#include <cstdlib>
int a[1000001],b[1000001];
int main()
{
   int n,x,i;
   scanf("%d",&n);
   for (i=1;i<=n;i++)
      scanf("%d%d",&a[i],&b[i]);
   x=0;
   for (i=n;i>=1;i--)
   {
      a[i]+=b[i]+x;
      x=a[i]/10;
      a[i]%=10;
   }
   for (i=1;i<=n;i++)
      printf("%d",a[i]);
   printf("\n");
   system("pause");
   return(0);
}
