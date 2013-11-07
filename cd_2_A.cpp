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
typedef map <string,int>::iterator data;
const int inf=1061109567;
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
char s[1100][40];
int b[1100];
map <string,int> a,p;
int main()
{
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      scanf("%s%d",s[i],&b[i]);
      a[s[i]]+=b[i];
   }
   int ans=-inf;
   for (data k=a.begin();k!=a.end();k++)
      ans=max(ans,k->second);
   for (int i=1;i<=n;i++)
   {
      if (a[s[i]]!=ans)
         continue;
      p[s[i]]+=b[i];
      if (p[s[i]]>=ans)
      {
         printf("%s\n",s[i]);
         break;
      }
   }
   system("pause");
   return(0);
}
