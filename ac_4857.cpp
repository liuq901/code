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
int a[110],next[110],f[110][110];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n;
      scanf("%d%*d",&n);
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      memset(next,0,sizeof(next));
      for (int i=1;i<=n;i++)
         for (int j=i+1;j<=n;j++)
            if (a[i]==a[j])
            {
               next[i]=j;
               break;
            }
      for (int i=n;i;i--)
      {
         f[i][i]=1;
         for (int j=i+1;j<=n;j++)
         {
            f[i][j]=inf;
            for (int k=i;k<j;k++)
               f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
            for (int k=next[i];k && k<=j;k=next[k])
               f[i][j]=min(f[i][j],f[i+1][k-1]+f[k][j]);
         }
      }
      static int id=0;
      printf("Case %d: %d\n",++id,f[1][n]);
   }
   system("pause");
   return(0);
}
