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
   string s;
   cin>>t;
   getline(cin,s);
   while (t--)
   {
      getline(cin,s);
      int l=s.size(),ans=0;
      bool flag=false;
      for (int i=0;i<l;i++)
      {
         if (s[i]>=0)
            continue;
         if (flag)
            ans++,flag=false;
         else
            flag=true;
      }
      cout<<ans<<endl;
   }
   system("pause");
   return(0);
}
