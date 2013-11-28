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
const double euler=0.57721566490153286;
double a[10010];
int main()
{
   void init();
   double calc(int);
   init();
   while (1)
   {
      int a,b;
      scanf("%d%d",&a,&b);
      if (!a && !b)
         break;
      static int id=0;
      printf("Case %d:\n",++id);
      if (!b && a%8)
      {
         printf("Situation Impossible.\n");
         continue;
      }
      int up,down;
      down=a/8+b;
      if (a>7*b)
         up=(a-7*b)/8+((a-7*b)%8!=0)+b;
      else
         up=b;
      double ans=(a+b)*(calc(down)-calc(up-1))/double(down-up+1);
      printf("On Average Bob Reaches Round %.2f\n",ans);
   }
   system("pause");
   return(0);
}
void init()
{
   a[0]=0;
   for (int i=1;i<=10000;i++)
      a[i]=a[i-1]+1.0/i;
}
double calc(int x)
{
   return(x<=10000?a[x]:log(x+1)+euler);
}
