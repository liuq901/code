#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const double eps=1e-7;
int L,a[90000];
int main()
{
   bool check(double);
   while (1)
   {
      int n;
      scanf("%d%d",&n,&L);
      if (!n && !L)
         break;
      double l=0,r=0;
      memset(a,0,sizeof(a));
      for (int i=1;i<=n;i++)
      {
         int x,y,z;
         scanf("%d%d%d",&x,&y,&z);
         for (int j=x;j<y;j++)
            a[j]=z;
         r=max(r,double(z));
      }
      while (r-l>eps)
      {
         double mid=(l+r)/2;
         if (check(mid))
            r=mid;
         else
            l=mid;
      }
      printf("%.6f\n",l);
   }
   system("pause");
   return(0);
}
bool check(double mid)
{
   double now=L;
   for (int i=0;i<86400;i++)
   {
      now=min(double(L),now+mid-a[i]);
      if (now<-eps)
         return(false);
   }
   double p=now;
   for (int i=0;i<86400;i++)
   {
      now=min(double(L),now+mid-a[i]);
      if (now<-eps)
         return(false);
   }
   if (now<p)
      return(false);
   return(true);
}
