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
ll f[60];
int main()
{
   f[0]=0,f[1]=1;
   for (int i=2;i<=50;i++)
      f[i]=f[i-1]+f[i-2];
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (n==-1)
         break;
      cout<<f[n]<<endl;
   }
   system("pause");
   return(0);
}
