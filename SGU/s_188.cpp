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
int v[30],l[30],ans[30];
int main()
{
   int n,t;
   scanf("%d%d",&n,&t);
   for (int i=1;i<=n;i++)
      scanf("%d",&l[i]);
   for (int i=1;i<=n;i++)
      scanf("%d",&v[i]);
   for (int i=1;i<n;i++)
      for (int j=i+1;j<=n;j++)
      {
         if (v[i]>0==v[j]>0)
            continue;
         int len;
         if (v[i]>0)
            len=l[i]<l[j]?l[j]-l[i]:1000-l[i]+l[j];
         else
            len=l[j]<l[i]?l[i]-l[j]:1000-l[j]+l[i];
         int s=t*(abs(v[i])+abs(v[j])),k=s/1000+(s%1000>=len);
         ans[i]+=k,ans[j]+=k;
      }
   for (int i=1;i<n;i++)
      printf("%d ",ans[i]);
   printf("%d\n",ans[n]);
   system("pause");
   return(0);
}
