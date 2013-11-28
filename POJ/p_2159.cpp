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
#define MAXN 1010
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
int main()
{
   int a[26]={0},b[26]={0};
   string s;
   cin>>s;
   int n=s.size();
   for (int i=0;i<n;i++)
      a[s[i]-'A']++;
   cin>>s;
   n=s.size();
   for (int i=0;i<n;i++)
      b[s[i]-'A']++;
   sort(a,a+26);
   sort(b,b+26);
   bool flag=true;
   for (int i=0;i<26;i++)
      if (a[i]!=b[i])
      {
         flag=false;
         break;
      }
   printf("%s\n",flag?"YES":"NO");
   system("pause");
   return(0);
}
