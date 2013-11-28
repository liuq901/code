#include <cstdio>
#include <cstdlib>
long long a[1000001];
int main()
{
   void init();
   int find(long long);
   init();
   int t;
   scanf("%d",&t);
   while (t--)
   {
      long long n;
      scanf("%lld",&n);
      bool flag=false;
      int l,r;
      l=0,r=find(n);
      while (l<=r)
      {
         if (a[l]+a[r]==n)
         {
            flag=true;
            break;
         }
         if (a[l]+a[r]<n)
            l++;
         else
            r--;
      }
      printf("%s\n",flag?"Yes":"No");
   }
   system("pause");
   return(0);
}
void init()
{
   for (int i=0;i<=1000000;i++)
      a[i]=(long long)i*i;
}
int find(long long p)
{
   int l=0,r=1000000,ans;
   while (l<=r)
   {
      int mid=l+r>>1;
      if (a[mid]<=p)
      {
         ans=mid;
         l=mid+1;
      }
      else
         r=mid-1;
   }
   return(ans);
}
