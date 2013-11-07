#include <cstdio>
#include <cstdlib>
#include <cstring>
int mid,sum,n,b[501],f[501],a[501][501];
int main()
{
   int hungary(int);
   int i,j,l,r,min,max,ans[501];
   scanf("%d",&n);
   max=-20000000;
   min=20000000;
   for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
      {
         scanf("%d",&a[i][j]);
         if (a[i][j]>max)
            max=a[i][j];
         if (a[i][j]<min)
            min=a[i][j];
      }
   l=min;
   r=max;
   while (1)
   {
      if (l>r)
         break;
      mid=(l+r)/2;
      sum=0;
      memset(f,0,sizeof(f));
      for (i=1;i<=n;i++)
      {
         memset(b,0,sizeof(b));
         hungary(i);
      }
      if (sum==n)
      {
         memcpy(ans,f,sizeof(f));
         ans[0]=mid;
         r=mid-1;
      }
      else
         l=mid+1;
   }
   printf("%d\n",ans[0]);
   for (i=1;i<=n;i++)
      printf("%d %d\n",ans[i],i);
   system("pause");
   return(0);
}
int hungary(int t)
{
   int i;
   for (i=1;i<=n;i++)
   {
      if (b[i] || a[t][i]>mid)
         continue;
      b[i]=1;
      if (!f[i])
      {
         sum++;
         f[i]=t;
         return(1);
      }
      if (hungary(f[i]))
      {
         f[i]=t;
         return(1);
      }
   }
   return(0);
}
