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
const double g=9.81;
int main()
{
   double l,h,w;
   scanf("%lf%lf%lf",&l,&h,&w);
   double t=sqrt((h-l/2)/50/g);
   double round=t*w/60;
   round-=floor(round);
   printf("%s\n",round>0.25 && round<0.75?"bread":"butter");
   system("pause");
   return(0);
}
