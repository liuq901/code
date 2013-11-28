#include <cstdio>
#include <cstdlib>
#include <utility>
#include <algorithm>
using namespace std;
pair <int,int> a[1010];
int main()
{
   int calc(int);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n,k;
      scanf("%d%d",&n,&k);
      int sum=0;
      for (int i=1;i<=n;i++)
      {
         scanf("%d%d",&a[i].first,&a[i].second);
         sum+=a[i].second;
      }
      if (sum<k)
         printf("UNLUCKY\n");
      else
      {
         sort(a+1,a+n+1);
         int l=1,r=n,ans;
         while (l<=r)
         {
            int mid=l+r>>1;
            if (calc(mid)>=k)
               r=mid-1,ans=a[mid].first;
            else
               l=mid+1;
         }
         printf("%d\n",ans);
      }
   }
   system("pause");
   return(0);
}
int calc(int n)
{
   int s=0;
   for (int i=1;i<=n;i++)
      s+=a[i].second;
   return(s);
}
