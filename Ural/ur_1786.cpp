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
const string t="Sandro";
int main()
{
   string s;
   cin>>s;
   int l=s.size(),ans=inf;
   for (int i=0;i<l;i++)
   {
      if (i+5==l)
         break;
      int sum=0;
      for (int j=0;j<6;j++)
      {
         sum+=islower(t[j])!=islower(s[i+j]);
         sum+=tolower(t[j])!=tolower(s[i+j]);
      }
      ans=min(ans,sum);
   }
   printf("%d\n",ans*5);
   system("pause");
   return(0);
}
