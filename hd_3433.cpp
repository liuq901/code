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
int n,m1,m2,a[60],b[60];
int main()
{
   bool check(int);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      scanf("%d%d%d",&n,&m1,&m2);
      for (int i=1;i<=n;i++)
         scanf("%d%d",&a[i],&b[i]);
      int l=0,r=2000010,ans;
      while (l<=r)
      {
         int mid=l+r>>1;
         if (check(mid))
            ans=mid,r=mid-1;
         else
            l=mid+1;
      }
      static int id=0;
      printf("Case %d: %d\n",++id,ans);
   }
   system("pause");
   return(0);
}
int f[60][210];
bool check(int limit)
{
   memset(f,-63,sizeof(f));
   f[0][0]=0;
   for (int i=1;i<=n;i++)
      for (int j=0;j<=m1;j++)
         for (int k=0;k<=min(j,limit/a[i]);k++)
            f[i][j]=max(f[i][j],f[i-1][j-k]+(limit-(a[i]*k))/b[i]);
   return(f[n][m1]>=m2);
}
