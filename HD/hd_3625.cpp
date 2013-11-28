#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
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
#define MAXN 30
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=(1<<30)-1;
const double eps=1e-7;
const double pi=acos(-1.0);
ld fac[MAXN],f[MAXN][MAXN];
int main()
{
   void init();
   ios::sync_with_stdio(false);
   init();
   int t;
   cin>>t;
   while (t--)
   {
      int n,k;
      cin>>n>>k;
      ld ans=0;
      for (int i=1;i<=k;i++)
         ans+=f[n][i];
      for (int i=1;i<k;i++)
         ans-=f[n-1][i];
      ans/=fac[n];
      cout<<setprecision(4)<<fixed<<ans<<endl;
   }
   system("pause");
   return(0);
}
ld c[MAXN][MAXN];
void init()
{
   int n=20;
   for (int i=1;i<=n;i++)
   {
      c[i][0]=c[i][i]=1;
      for (int j=1;j<i;j++)
         c[i][j]=c[i-1][j-1]+c[i-1][j];
   }
   fac[0]=1;
   for (int i=1;i<=n;i++)
      fac[i]=fac[i-1]*i;
   for (int i=1;i<=n;i++)
   {
      f[i][1]=fac[i-1];
      for (int j=2;j<=i;j++)
         for (int k=1;k<i;k++)
            f[i][j]+=f[i-k][j-1]*fac[k-1]*c[i][k];
   }
   for (int i=1;i<=n;i++)
      for (int j=1;j<=i;j++)
         f[i][j]/=fac[j];
}
