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
const double pi=acos(-1.0);
const double eps=1e-7;
int main()
{
   ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while (t--)
   {
      int x1,y1,z1,x2,y2,z2;
      cin>>x1>>y1>>z1>>x2>>y2>>z2;
      x1+=x2,y1+=y2,z1+=z2;
      if (z1>=60)
         y1++,z1-=60;
      if (y1>=60)
         x1++,y1-=60;
      cout<<x1<<" "<<y1<<" "<<z1<<endl;
   }
   system("pause");
   return(0);
}
