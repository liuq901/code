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
   while (1)
   {
      char ch1,ch2;
      cin>>ch1;
      if (ch1=='E')
         break;
      double t,d,h;
      switch (ch1)
      {
      case 'T':
         scanf("%lf",&t);
         break;
      case 'D':
         scanf("%lf",&d);
         break;
      case 'H':
         scanf("%lf",&h);
         break;
      }
      cin>>ch2;
      switch (ch2)
      {
      case 'T':
         scanf("%lf",&t);
         break;
      case 'D':
         scanf("%lf",&d);
         break;
      case 'H':
         scanf("%lf",&h);
         break;
      }
      if (ch1>ch2)
         swap(ch1,ch2);
      if (ch1=='D' && ch2=='T')
      {
         double e=6.11*exp(5417.7530*((1/273.16)-(1/(d+273.16))));
         h=(0.5555)*(e-10.0)+t;
      }
      else if (ch1=='H' && ch2=='T')
      {
         double e=(h-t)/(0.5555)+10.0;
         d=1/(1/273.16-(log(e/6.11))/5417.7530)-273.16;
      }
      else
      {
         double e=6.11*exp(5417.7530*((1/273.16)-(1/(d+273.16))));
         t=h-(0.5555)*(e-10);
      }
      printf("T %.1f D %.1f H %.1f\n",t,d,h);
   }
   system("pause");
   return(0);
}
