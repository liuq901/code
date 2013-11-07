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
bool f[110];
int a[110],ans[110];
int main()
{
   int n,now;
   scanf("%d%d",&n,&now);
   for (int i=1;i<=n;i++)
   {
      scanf("%d",&a[i]);
      f[a[i]]=true;
   }
   for (int i=1;i<=n;i++)
   {
      int x=a[i];
      if (!f[x])
         continue;
      int p=now>x?-1:1;
      for (int j=now;j!=x;j+=p)
         if (f[j])
         {
            f[j]=false;
            ans[++ans[0]]=j;
         }
      f[x]=false;
      ans[++ans[0]]=x;
   }
   for (int i=1;i<=ans[0];i++)
      printf("%d%c",ans[i],i==ans[0]?'\n':' ');
   system("pause");
   return(0);
}
