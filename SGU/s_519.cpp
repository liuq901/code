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
int a[110][110];
int main()
{
   int n,m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
      {
         char ch;
         cin>>ch;
         a[i][j]=ch-'0';
      }
   int ans=0;
   for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
      {
         ans+=(a[i][j]<<2)+((a[i][j]>0)<<1);
         ans-=min(a[i][j],a[i-1][j])+min(a[i][j],a[i+1][j])+min(a[i][j],a[i][j-1])+min(a[i][j],a[i][j+1]);
      }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
