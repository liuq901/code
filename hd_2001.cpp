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
int main()
{
   double dist(double,double,double,double);
   ios::sync_with_stdio(false);
   double x1,y1,x2,y2;
   while (cin>>x1>>y1>>x2>>y2)
      cout<<setprecision(2)<<fixed<<dist(x1,y1,x2,y2)<<endl;
   system("pause");
   return(0);
}
double dist(double x1,double y1,double x2,double y2)
{
   return(sqrt(SQR(x1-x2)+SQR(y1-y2)));
}
