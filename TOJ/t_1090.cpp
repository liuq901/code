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
int ans[210];
char a[210][210];
int main()
{
   int n,m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
         cin>>a[i][j];
   for (int i=1;i<=m;i++)
   {
      int sum=0;
      for (int j=1;j<=n;j++)
      {
         a[j][i]=='0'?sum++:sum=0;
         ans[sum]++;
      }
   }
   for (int i=1;i<=n;i++)
      if (ans[i]!=ans[i+1])
         printf("%d %d\n",i,ans[i]-ans[i+1]);
   system("pause");
   return(0);
}
