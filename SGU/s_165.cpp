#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
#include <cstdarg>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <numeric>
#include <functional>
#include <bitset>
#include <complex>
#include <iterator>
#include <memory>
#define SQR(x) ((x)*(x))
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
struct data
{
   int pos;
   double height;
};
bool operator <(data a,data b)
{
   return(a.height<b.height);
}
data a[6010];
int ans[6010];
int main()
{
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      double x;
      scanf("%lf",&x);
      a[i].pos=i;
      a[i].height=x-2;
   }
   sort(a+1,a+n+1);
   double s=0;
   int l=1,r=n,t=0;
   while (l<=r)
      if (s>0)
      {
         ans[++t]=a[l].pos;
         s+=a[l++].height;
      }
      else
      {
         ans[++t]=a[r].pos;
         s+=a[r--].height;
      }
   printf("yes\n");
   for (int i=1;i<n;i++)
      printf("%d ",ans[i]);
   printf("%d\n",ans[n]);
   system("pause");
   return(0);
}
