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
int c[10010],p[10010],ans[10010],a[100010],d[100010],pre[100010];
int main()
{
   int n;
   scanf("%d",&n);
   memset(c,63,sizeof(c));
   for (int i=1;i<=n;i++)
   {
      int x;
      scanf("%d",&x);
      a[i]=x;
      if (d[i-1]+1<c[x])
      {
         d[i]=d[i-1]+1;
         pre[i]=i-1;
      }
      else
      {
         d[i]=c[x];
         pre[i]=p[x];
      }
      if (d[i]<c[x])
      {
         c[x]=d[i];
         p[x]=pre[i];
      }
   }
   int m=0;
   for (int i=n;i;i=pre[i])
      ans[++m]=a[i];
   for (int i=m;i;i--)
      printf("%d%c",ans[i],i==1?'\n':' ');
   system("pause");
   return(0);
}
