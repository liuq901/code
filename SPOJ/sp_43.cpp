#include <cstdio>
#include <cstdlib>
int n,m,a[501];
int main()
{
   int work(long long);
   void print(long long);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      scanf("%d%d",&n,&m);
      long long r=0;
      for (int i=1;i<=n;i++)
      {
         scanf("%d",&a[i]);
         r+=a[i];
      }
      long long l=0,ans;
      while (l<=r)
      {
         long long mid=l+r>>1;
         if (work(mid)<=m)
         {
            ans=mid;
            r=mid-1;
         }
         else
            l=mid+1;
      }
      print(ans);
   }
   system("pause");
   return(0);
}
int work(long long x)
{
   long long s=x;
   int ans=0;
   for (int i=n;i>=1;i--)
   {
      if (a[i]>x)
         return(20000000);
      if (a[i]<=s)
         s-=a[i];
      else
      {
         ans++;
         s=x-a[i];
      }
   }
   return(ans+1);
}
void print(long long ans)
{
   int t=m,l[501],r[501];
   long long s=ans;
   r[m]=n;
   for (int i=n;i>=1;i--)
   {
      if (i==t-1)
      {
         l[t]=i+1;
         for (int j=1;j<t;j++)
            l[j]=r[j]=j;
         break;
      }
      if (a[i]<=s)
         s-=a[i];
      else
      {
         l[t]=i+1;
         r[--t]=i;
         s=ans-a[i];      
      }
   }
   l[1]=1;
   for (int i=1;i<=m-1;i++)
   {
      for (int j=l[i];j<=r[i];j++)
         printf("%d ",a[j]);
      printf("/ ");
   }
   for (int i=l[m];i<n;i++)
      printf("%d ",a[i]);
   printf("%d\n",a[n]);
}
