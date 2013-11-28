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
int f[1010][1010];
int main()
{
   int n;
   scanf("%d",&n);
   f[1][1]=1;
   for (int i=2;i<=n;i++)
      for (int j=2;j<=n;j++)
         f[i][j]=max(f[i-1][j],f[i-1][j-1])+j*(i-j+2);
   int ans=0;
   for (int i=1;i<=n;i++)
      ans=max(ans,f[n][i]);
   printf("%d\n",ans);
   system("pause");
   return(0);
}
