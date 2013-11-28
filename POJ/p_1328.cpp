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
int x[1010],y[1010];
pair <double,double> a[1010];
int main()
{
   int id=0;
   while (1)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      if (!n && !m)
         break;
      for (int i=1;i<=n;i++)
         scanf("%d%d",&x[i],&y[i]);
      bool flag=true;
      for (int i=1;i<=n;i++)
      {
         if (m<y[i])
         {
            flag=false;
            break;
         }
         double len=sqrt(SQR(m)-SQR(y[i]));
         a[i].first=x[i]+len,a[i].second=x[i]-len;
      }
      if (!flag)
         printf("Case %d: -1\n",++id);
      else
      {
         sort(a+1,a+n+1);
         int ans=0;
         double last=-1e100;
         for (int i=1;i<=n;i++)
            if (last<a[i].second)
               ans++,last=a[i].first;
         printf("Case %d: %d\n",++id,ans);
      }
   }
   system("pause");
   return(0);
}
