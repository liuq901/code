#include <cstdio>
#include <cstdlib>
#include <cstring>
const int q=10000;
int main()
{
   int n,i,j,max;
   int a[3001],c[3001],f[3001],flag[26000];
   scanf("%d",&n);
   for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
   for (i=1;i<=n;i++)
   {
      f[i]=1;
      for (j=1;j<=i-1;j++)
         if (a[j]>a[i] && f[j]+1>f[i])
            f[i]=f[j]+1;
   }
   max=0;
   for (i=1;i<=n;i++)
      if (f[i]>max)
         max=f[i];
   printf("%d ",max);
   memset(c,0,sizeof(c));
   for (i=1;i<=n;i++)
      if (f[i]==1)
         c[i]=1;
      else
      {
         memset(flag,0,sizeof(flag));
         for (j=i-1;j>=1;j--)
            if (f[j]+1==f[i] && a[j]>a[i] && !flag[a[j]])
            {
               c[i]=(c[i]+c[j])%q;
               flag[a[j]]=1;
            }
      }
   memset(flag,0,sizeof(flag));
   int s=0;
   for (i=n;i>=1;i--)
      if (f[i]==max && !flag[a[i]])
      {
         s=(s+c[i])%q;
         flag[a[i]]=1;
      }
   printf("%d\n",s);
   system("pause");
   return(0);
}
