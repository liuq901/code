#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;
const double eps=1e-7;
pair <double,double> a[1010],b[1010];
int main()
{
   bool check(int,pair <double,double> *,double);
   while (1)
   {
      int n,m;
      double w;
      scanf("%d%d%lf",&n,&m,&w);
      if (!n && !m && fabs(w)<eps)
         break;
      w/=2;
      for (int i=1;i<=n;i++)
      {
         double x;
         scanf("%lf",&x);
         a[i].first=x-w,a[i].second=x+w;
      }
      for (int i=1;i<=m;i++)
      {
         double x;
         scanf("%lf",&x);
         b[i].first=x-w,b[i].second=x+w;
      }
      printf("%s\n",check(n,a,75.0) && check(m,b,100.0)?"YES":"NO");
   }
   system("pause");
   return(0);
}
bool check(int n,pair <double,double> *a,double len)
{
   sort(a+1,a+n+1);
   for (int i=1;i<n;i++)
      if (a[i].second<a[i+1].first)
         return(false);
   if (a[1].first>0 || a[n].second<len)
      return(false);
   return(true);
}
