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
int a[11000],x[11000];
ll b[11000];
int main()
{
   int n,m;
   scanf("%d%d",&n,&m);
   n+=m-1;
   for (int i=1;i<=n;i++)
      scanf("%d",&a[i]);
   b[0]=0;
   for (int i=1;i<=n;i++)
   {
      if (i+m-1>n)
         break;
      int l=-(1<<17),r=1<<17;
      while (l<=r)
      {
         int mid=l+r>>1;
         bool flag=true;
         ll now=b[i-1];
         for (int j=1;j<=m;j++)
         {
            now+=mid;
            if (now<a[i+j-1])
            {
               flag=false;
               break;
            }
         }
         if (flag)
            x[i]=mid,r=mid-1;
         else
            l=mid+1;
      }
      b[i]=b[i-1]+x[i];
   }
   for (int i=1;i<=n;i++)
   {
      printf("%d",x[i]);
      if (i+m-1==n)
      {
         printf("\n");
         break;
      }
      printf(" ");
   }
   system("pause");
   return(0);
}
