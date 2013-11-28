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
const int c[]={0,1,2,3,4,2,3,4,1,3,4,1,2,4,1,2,3};
const string ans[]={"","hong","bai","qing","huang"};
int main()
{
   int n;
   scanf("%d",&n);
   n=(n-1)%16+1;
   printf("%s\n",ans[c[n]].c_str());
   int i=n;
   while (i%4!=1)
      i--;
   int l=i;
   i=i;
   while (i%4)
      i++;
   int r=i;
   for (int i=l;i<=r;i++)
      printf("%s%c",ans[c[i]].c_str(),i==r?'\n':' ');
   system("pause");
   return(0);
}
