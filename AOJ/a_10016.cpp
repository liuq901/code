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
   while (1)
   {
      int a,b,c;
      scanf("%d%d%d",&a,&b,&c);
      if (a==-1 && b==-1 && c==-1)
         break;
      if (a==-1 || b==-1)
         printf("F\n");
      else if (a+b>=80)
         printf("A\n");
      else if (a+b>=65)
         printf("B\n");
      else if (a+b>=50 || a+b>=30 && c>=50)
         printf("C\n");
      else if (a+b>=30)
         printf("D\n");
      else
         printf("F\n");
   }
   system("pause");
   return(0);
}
