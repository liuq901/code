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
vector <int> a[20];
bitset <110> f[20];
bool ans[20];
int main()
{
   int n,m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=n;i++)
   {
      int k;
      scanf("%d",&k);
      a[i].resize(k);
      for (int j=0;j<k;j++)
      {
         scanf("%d",&a[i][j]);
         f[i].set(a[i][j]);
      }
   }
   for (int i=1;i<=m;i++)
   {
      int p;
      scanf("%d",&p);
      memset(ans,0,sizeof(ans));
      for (int j=1;j<=p;j++)
      {
         int x;
         scanf("%d",&x);
         for (int k=1;k<=n;k++)
            if (x>0 && !f[k].test(x) || x<0 && f[k].test(-x))
               ans[k]=true;
      }
      printf("%d\n",count(ans+1,ans+n+1,false));
      for (int i=1;i<=n;i++)
      {
         if (ans[i])
            continue;
         printf("%d",a[i].size());
         for (int j=0;j<a[i].size();j++)
            printf(" %d",a[i][j]);
         printf("\n");
      }
   }
   system("pause");
   return(0);
}
