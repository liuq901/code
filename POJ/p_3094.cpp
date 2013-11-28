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
int main()
{
   while (1)
   {
      string s;
      getline(cin,s);
      if (s=="#")
         break;
      int n=s.size(),ans=0;
      for (int i=0;i<n;i++)
         ans+=(i+1)*(s[i]==' '?0:s[i]-'A'+1);
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
