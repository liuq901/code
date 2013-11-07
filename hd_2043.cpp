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
   bool flag;
   int t;
   scanf("%d",&t);
   while (t--)
   {
      string s;
      cin>>s;
      int l=s.length();
      bool f1,f2,f3,f4,flag;
      f1=f2=f3=f4=false;
      for (int i=0;i<l;i++)
      {
         f1|=isupper(s[i]);
         f2|=islower(s[i]);
         f3|=isdigit(s[i]);
         f4|=ispunct(s[i]);
      }
      flag=l>=8 && l<=16;
      printf("%s\n",flag && f1+f2+f3+f4>=3?"YES":"NO");
   }
   system("pause");
   return(0);
}
