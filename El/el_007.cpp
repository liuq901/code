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
#define MAXN 26
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
int s[MAXN][MAXN][MAXN];
int main()
{
   int n,m,d;
   scanf("%d%d%d",&n,&m,&d);
   for (int i=1;i<=d;i++)
      for (int j=1;j<=n;j++)
         for (int k=1;k<=m;k++)
         {
            int x;
            scanf("%d",&x);
            s[i][j][k]=s[i][j-1][k]+s[i][j][k-1]-s[i][j-1][k-1]+x;
         }
   int ans=-inf;
   for (int x0=1;x0<=n;x0++)
      for (int x1=x0;x1<=n;x1++)
         for (int y0=1;y0<=m;y0++)
            for (int y1=y0;y1<=m;y1++)
            {
               int a[MAXN];
               for (int i=1;i<=d;i++)
                  a[i]=s[i][x1][y1]-s[i][x1][y0-1]-s[i][x0-1][y1]+s[i][x0-1][y0-1];
               int sum=0;
               for (int i=1;i<=d;i++)
               {
                  sum=max(a[i],sum+a[i]);
                  ans=max(ans,sum);
               }
            }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
