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
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n,a[201]={0};
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         x=x+1>>1,y=y+1>>1;
         if (x>y)
            swap(x,y);
         for (int j=x;j<=y;j++)
            a[j]++;
      }
      int ans=0;
      for (int i=1;i<=200;i++)
         ans=max(ans,a[i]);
      printf("%d\n",ans*10);
   }
   system("pause");
   return(0);
}
