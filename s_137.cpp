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
int a[1010];
int main()
{
   int n,k;
   scanf("%d%d",&n,&k);
   int p=1;
   while (k*p%n!=n-1)
      p++;
   for (int i=p;i!=n-1;i=(i+p)%n)
      a[i]=1;
   a[n-1]=1;
   printf("%d",k/n);
   for (int i=1;i<n;i++)
      printf(" %d",k/n+a[i]);
   printf("\n");
   system("pause");
   return(0);
}
