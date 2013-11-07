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
   double a,b,theta;
   scanf("%lf%lf%lf",&a,&b,&theta);
   theta*=pi/180;
   double area=a*b*sin(theta)/2;
   double c=sqrt(SQR(a)+SQR(b)-2*a*b*cos(theta));
   double h=area*2/a;
   printf("%.10f\n%.10f\n%.10f\n",area,a+b+c,h);
   system("pause");
   return(0);
}
