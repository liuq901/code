#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a[100010];
int main()
{
   int n;
   while (scanf("%d",&n)==1)
   {
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      sort(a+1,a+n+1);
      int ans=0;
      while (n>=4)
      {
         ans+=min((a[2]<<1)+a[1]+a[n],(a[1]<<1)+a[n-1]+a[n]);
         n-=2;
      }
      ans+=a[n];
      if (n==3)
         ans+=a[1]+a[2];
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
