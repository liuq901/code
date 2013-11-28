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
const int c[]={7,6,5,4,3,2};
int main()
{
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n,a,b;
      scanf("%d%d%d",&n,&a,&b);
      for (int i=0;i<min(n,6);i++)
         a+=c[i];
      n-=6;
      if (n>0)
         a+=n<<3;
      printf("%s\n",a>=b?"Yes":"No");
   }
   system("pause");
   return(0);
}
