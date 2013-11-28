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
int a[10010],f[110][110];
int main()
{
   int n,m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=n;i++)
      scanf("%d",&a[i]);
   memset(f,63,sizeof(f));
   for (int i=1;i<=n+1;i++)
      for (int j=1;j<=min(i,m-1);j++)
         if (i>m)
            f[i%m][j]=min(f[i%m][j-1],f[(i-j)%m][m-j]+a[i]);
         else
            f[i%m][j]=min(f[i%m][j-1],a[i]+a[i-j]);
   printf("%d\n",f[(n+1)%m][m-1]);
   system("pause");
   return(0);
}
