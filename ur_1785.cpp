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
   int n;
   scanf("%d",&n);
   if (n<5)
      printf("few\n");
   else if (n<10)
      printf("several\n");
   else if (n<20)
      printf("pack\n");
   else if (n<50)
      printf("lots\n");
   else if (n<100)
      printf("horde\n");
   else if (n<250)
      printf("throng\n");
   else if (n<500)
      printf("swarm\n");
   else if (n<1000)
      printf("zounds\n");
   else
      printf("legion\n");
   system("pause");
   return(0);
}
