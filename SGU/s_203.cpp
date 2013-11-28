#include <cstdio>
#include <cstdlib>
long long a[500001],b[500001];
int main()
{
   long long min,ans,max;
   int n,i,p,q;
   int f[2];
   scanf("%d",&n);
   for (i=1;i<=n;i++)
      scanf("%I64d",&a[i]);
   p=1;
   q=1;
   b[0]=0;
   ans=0;
   max=1;
   for (i=1;i<=60;i++)
      max*=2;
   for (i=1;i<=n-1;i++)
   {
      min=max;
      if (p+1<=n && a[p]+a[p+1]<min)
      {
         f[0]=f[1]=0;
         min=a[p]+a[p+1];
      }
      if (q+1<=b[0] && b[q]+b[q+1]<min)
      {
         f[0]=f[1]=1;
         min=b[q]+b[q+1];
      }
      if (p<=n && q<=b[0] && a[p]+b[q]<min)
      {
         f[0]=0;
         f[1]=1;
         min=a[p]+b[q];
      }
      ans+=min;
      if (!f[0])
         p++;
      else
         q++;
      if (!f[1])
         p++;
      else
         q++;
      b[0]++;
      b[b[0]]=min;
   }
   printf("%I64d\n",ans);
   system("pause");
   return(0);
}
