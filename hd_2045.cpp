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
#define MAXN 1010
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const double eps=1e-7;
const double pi=acos(-1.0);
ll f[3][51][3];
int main()
{
   int n;
   while (scanf("%d",&n)!=EOF)
   {
      memset(f,0,sizeof(f));
      f[0][1][0]=f[1][1][1]=f[2][1][2]=1;
      for (int p=0;p<=2;p++)
         for (int i=2;i<=n;i++)
            for (int j=0;j<=2;j++)
               for (int k=0;k<=2;k++)
               {
                  if (j==k)
                     continue;
                  f[p][i][k]+=f[p][i-1][j];
               }
      ll ans=0;
      for (int p=0;p<=2;p++)
         for (int j=0;j<=2;j++)
         {
            if (n!=1 && p==j)
               continue;
            ans+=f[p][n][j];
         }
      cout<<ans<<endl;
   }
   system("pause");
   return(0);
}
