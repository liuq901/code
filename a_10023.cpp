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
int main()
{
   while (1)
   {
      string s;
      cin>>s;
      if (s=="-")
         break;
      int n;
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
      {
         int x;
         scanf("%d",&x);
         s=s.substr(x)+s.substr(0,x);
      }
      printf("%s\n",s.c_str());
   }
   system("pause");
   return(0);
}
