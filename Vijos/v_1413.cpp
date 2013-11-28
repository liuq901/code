#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int i,j,n,ans;
   int a[26];
   scanf("%d",&n);
   memset(a,0,sizeof(a));
   a[0]=1;
   for (i=1;i<=n;i++)
      for (j=i;j>=1;j--)
         a[j]+=a[j-1];
   ans=0;
   for (i=1;i<=n;i++)
   {
      for (j=1;j<=n-i;j++)
         a[i]=a[i]*i%19900801;
      ans+=a[i];
      ans%=19900801;
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
