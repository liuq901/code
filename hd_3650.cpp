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
#define MAXN 110
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const double eps=1e-7;
const double pi=acos(-1.0);
pair <int,int> a[MAXN];
int main()
{
   ios::sync_with_stdio(false);
   while (1)
   {
      int n;
      cin>>n;
      if (!n)
         break;
      for (int i=1;i<=n;i++)
      {
         int l,r;
         cin>>l>>r;
         a[i].first=l,a[i].second=r;
      }
      int pos[110],m=n;
      for (int i=1;i<=n;i++)
         pos[i]=i;
      sort(a+1,a+n+1);
      int ans=0,sum=0;
      while (m)
      {
         bool f[110]={0};
         f[1]=true;
         int t=a[pos[1]].second;
         for (int i=2;i<=m;i++)
         {
            int x=a[pos[i]].first;
            if (x>t)
            {
               f[i]=true;
               t=a[pos[i]].second;
            }
         }
         t=0;
         for (int i=1;i<=m;i++)
            if (!f[i])
               pos[++t]=pos[i];
         m=t;
         ans++;
      }
      cout<<ans<<endl;
   }
   system("pause");
   return(0);
}
