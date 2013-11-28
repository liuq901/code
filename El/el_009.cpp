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
#define MAXN 1010
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
const int m=100000000;
int a[3][30];
int main()
{
   void plus(int *,int *,int *);
   int n;
   scanf("%d",&n);
   a[0][0]=a[0][1]=a[1][0]=a[1][1]=1;
   for (int i=2;i<=n;i++)
      plus(a[(i-2)%3],a[(i-1)%3],a[i%3]);
   int p=n%3;
   printf("%d",a[p][a[p][0]]);
   for (int i=a[p][0]-1;i;i--)
      printf("%08d",a[p][i]);
   printf("\n");
   system("pause");
   return(0);
}
void plus(int *a,int *b,int *c)
{
   c[0]=b[0];
   int x=0;
   for (int i=1;i<=c[0];i++)
   {
      c[i]=a[i]+b[i]+x;
      x=c[i]/m;
      c[i]%=m;
   }
   if (x)
      c[++c[0]]=x;
}
