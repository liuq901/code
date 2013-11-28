#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
double a[510];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n;
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
         scanf("%lf",&a[i]);
      sort(a+1,a+n+1);
      double ans=n&1?a[n+1>>1]:(a[n>>1]+a[(n>>1)+1])/2;
      printf("%.3f\n",ans);
   }
   system("pause");
   return(0);
}
