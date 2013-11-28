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
   string x,s;
   cin>>x;
   for (int i=0;i<x.size();i++)
      x[i]=tolower(x[i]);
   int ans=0;
   while (1)
   {
      cin>>s;
      if (s=="END_OF_TEXT")
         break;
      for (int i=0;i<s.size();i++)
         s[i]=tolower(s[i]);
      ans+=x==s;
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
