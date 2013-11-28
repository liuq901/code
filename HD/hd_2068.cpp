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
ll f[30],c[30][30];
int main()
{
   void init();
   init();
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      ll ans=1;
      for (int i=0;i<=n>>1;i++)
         ans+=c[n][i]*f[i];
      cout<<ans<<endl;
   }
   system("pause");
   return(0);
}
void init()
{
   f[1]=0,f[2]=1;
   for (int i=3;i<26;i++)
      f[i]=(i-1)*(f[i-1]+f[i-2]);
   for (int i=1;i<26;i++)
   {
      c[i][0]=c[i][i]=1;
      for (int j=1;j<i;j++)
         c[i][j]=c[i-1][j-1]+c[i-1][j];
   }
}
