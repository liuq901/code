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
#define MAXN 110
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const double pi=acos(-1.0);
const double eps=1e-7;
const int mod=1000000007;
const int inf=1061109567;
bool f[MAXN][MAXN];
int up[MAXN][MAXN],Right[MAXN][MAXN];
int main()
{
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      f[x][y]=true;
   }
   for (int i=0;i<=100;i++)
      for (int j=0;j<=100;j++)
      {
         for (int k=i+1;k<=100;k++)
            if (f[k][j] || k==100)
            {
               Right[i][j]=k-i;
               break;
            }
         for (int k=j+1;k<=100;k++)
            if (f[i][k] || k==100)
            {
               up[i][j]=k-j;
               break;
            }
      }
   int ans=0;
   for (int i=0;i<=100;i++)
      for (int j=0;j<=100;j++)
      {
         int height=100-j;
         for (int k=1;k<=Right[i][j];k++)
         {
            ans=max(ans,height*k);
            height=min(height,up[i+k][j]);
         }
      }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
