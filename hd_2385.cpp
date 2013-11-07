#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
#include <cstdarg>
#include <iostream>
#include <iomanip>
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
#define MAXN 1010
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
map <int,int> a;
typedef map <int,int>::iterator data;
int main()
{
   int t;
   scanf("%d",&t);
   while (t--)
   {
      a.clear();
      int n;
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
      {
         int x,p,m;
         scanf("%d%d%d",&x,&p,&m);
         int sum=min(m,x);
         if (m>x && !a.empty() && a.begin()->first<p)
         {
            int t=m-x;
            while (1)
            {
               if (a.empty() || a.begin()->first>=p)
                  break;
               if (t<a.begin()->second)
               {
                  sum+=t,a.begin()->second-=t;
                  break;
               }
               t-=a.begin()->second;
               sum+=a.begin()->second;
               a.erase(a.begin());
            }
         }
         a[p]+=sum;
         if (sum<x)
            a[0]+=x-sum;
      }
      ll ans=0;
      for (data k=a.begin();k!=a.end();k++)
         ans+=ll(k->first)*k->second;
      cout<<ans<<endl;
   }
   system("pause");
   return(0);
}
