#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
const double eps=1e-7;
struct point
{
   int value;
   double angle;
};
bool operator <(point a,point b)
{
   return(a.angle<b.angle);
}
point a[100010];
ll b[100010],c[100010];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n;
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
      {
         int x,y;
         scanf("%d%d%d",&a[i].value,&x,&y);
         a[i].angle=atan2(double(y),double(x));
      }
      sort(a+1,a+n+1);
      b[1]=a[1].value;
      int m=1;
      for (int i=2;i<=n;i++)
      {
         if (fabs(a[i].angle-a[i-1].angle)<eps)
         {
            b[m]+=a[i].value;
            continue;
         }
         b[++m]=a[i].value;
      }
      ll ans=0,sum=0,now=0,value=0,real=0;
      for (int i=1;i<=m;i++)
      {
         sum+=b[i];
         now=max(now+b[i],b[i]);
         value=min(value+b[i],b[i]);
         real=min(real,value);
         ans=max(ans,now);
      }
      ans=max(ans,sum-real);
      printf("%lld\n",ans);
   }
   system("pause");
   return(0);
}
