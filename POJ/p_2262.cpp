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
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
int a[1000001];
bool f[1000001];
int main()
{
   void init();
   init();
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      for (int i=1;i<=a[0];i++)
      {
         int x=a[i],y=n-a[i];
         if (!f[x] && !f[y])
         {
            printf("%d = %d + %d\n",n,x,y);
            break;
         }
      }
   }
   system("pause");
   return(0);
}
void init()
{
   int n=1000000,limit=int(sqrt(n))+3;
   for (int i=2;i<=limit;i++)
   {
      if (f[i])
         continue;
      for (int j=i;i*j<=n;j++)
         f[i*j]=true;
   }
   for (int i=2;i<=n;i++)
      if (!f[i])
         a[++a[0]]=i;
}
