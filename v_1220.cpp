#include <cstdio>
#include <cstdlib>
int main()
{
   int i,j,n,ans;
   int a[1001];
   scanf("%d",&n);
   for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
   ans=a[n];
   for (i=n-1;i>=1;i--)
   {
      for (j=1;j<=i;j++)
         a[j]=a[j+1]-a[j];
      ans+=a[i];
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
