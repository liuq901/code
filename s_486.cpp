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
   string a,b;
   cin>>a>>b;
   int s1,s2;
   s1=s2=0;
   for (int i=0;i<4;i++)
      s1+=a[i]==b[i];
   for (int i=0;i<4;i++)
      for (int j=0;j<4;j++)
         s2+=a[i]==b[j];
   printf("%d %d\n",s1,s2-s1);
   system("pause");
   return(0);
}
