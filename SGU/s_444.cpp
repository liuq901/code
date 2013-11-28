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
int f[1000010];
int main()
{
   int a,b;
   scanf("%d%d",&a,&b);
   a%=b;
   int s1,s2;
   s1=s2=0;
   while (a)
   {
      s1++;
      if (f[a])
      {
         s2=s1-f[a];
         s1=f[a]-1;
         break;
      }
      else
         f[a]=s1;
      int t=a*10/b;
      a=a*10%b;
   }
   printf("%d %d\n",s1,s2);
   system("pause");
   return(0);
}
