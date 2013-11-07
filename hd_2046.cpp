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
ll ans[51];
int main()
{
   void init();
   init();
   int n;
   while (cin>>n)
      cout<<ans[n]<<endl;
   system("pause");
   return(0);
}
void init()
{
   ans[1]=1,ans[2]=2,ans[3]=3;
   for (int i=4;i<=50;i++)
      ans[i]=ans[i-1]+ans[i-2];
}
