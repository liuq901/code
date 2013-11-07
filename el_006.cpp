#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
#include <cstdarg>
#include <iostream>
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
#define MAXN 10010
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
bool f[MAXN];
int main()
{
   int n;
   scanf("%d",&n);
   f[0]=true;
   for (int i=1;i<=3;i++)
      for (int j=n;j;j--)
      {
         if (f[j])
            continue;
         for (int k=1;k<=100;k++)
         {
            int x=SQR(k);
            if (x>j)
               break;
            f[j]=f[j-x];
            if (f[j])
               break;
         }
      }
   printf("%d\n",count(f,f+n+1,false));
   system("pause");
   return(0);
}
