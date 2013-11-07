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
int b[65],a[110][65];
int main()
{
   int n;
   scanf("%d",&n);
   int limit=0;
   for (int i=1;i<=n;i++)
   {
      ll x;
      cin>>x;
      int j=0;
      while (x)
      {
         a[i][++j]=x&1;
         x>>=1;
      }
      limit=max(limit,j);
   }
   ll ans=0;
   for (int i=1;i<=limit;i++)
      b[i]=1;
   for (int i=limit;i;i--)
   {
      int t=0;
      for (int j=1;j<=n;j++)
         if (a[j][i])
         {
            t=j;
            break;
         }
      if (!t)
      {
         if (!b[i])
            ans+=1LL<<i-1;
         continue;
      }
      for (int j=i-1;j;j--)
         if (a[t][j])
         {
            for (int k=1;k<=n;k++)
               a[k][j]^=a[k][i];
            b[j]^=b[i];
         }
      ans+=1LL<<i-1;
   }
   cout<<ans<<endl;
   system("pause");
   return(0);
}
