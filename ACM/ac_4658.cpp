#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
struct point
{
   int x,y,pos;
   double angle;
};
bool operator <(point a,point b)
{
   return(a.angle<b.angle);
}
point a[10010];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n,k;
      scanf("%d%d",&n,&k);
      for (int i=1;i<=n;i++)
      {
         scanf("%d%d",&a[i].x,&a[i].y);
         a[i].pos=i;
         if (a[i].x<a[1].x || a[i].x==a[1].x && a[i].y<a[1].y)
            swap(a[1],a[i]);
      }
      for (int i=2;i<=n;i++)
         a[i].angle=atan2(double(a[i].y-a[1].y),double(a[i].x-a[1].x));
      sort(a+2,a+n+1);
      for (int i=1;i<=k;i++)
         printf("%d\n",a[i].pos);
   }
   system("pause");
   return(0);
}
