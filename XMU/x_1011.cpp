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
#define MAXN 100010
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const double pi=acos(-1.0);
const double eps=1e-7;
const int mod=1000000007;
const int inf=1061109567;
int ans[MAXN],a[MAXN];
int main()
{
   int n,m,num;
   scanf("%d%d",&n,&m);
   printf("%d.",n/m);
   num=n/m?int(log10(n/m))+2:2;
   n%=m;
   int t=0,now;
   while (1)
   {
      t++;
      a[n]=t;
      ans[t]=n*10/m;
      n=n*10%m;
      if (a[n])
      {
         now=n;
         break;
      }
      if (!n)
      {
         now=0;
         break;
      }
   }
   if (!now)
   {
      for (int i=1;i<=t;i++)
      {         
         printf("%d",ans[i]);
         num++;
         if (!(num%76))
            printf("\n");
      }
      printf("\n");
   }
   else
   {
      for (int i=1;i<=t;i++)
      {
         if (i==a[now])
         {
            printf("(");
            num++;
         }
         printf("%d",ans[i]);
         num++;
         if (!(num%76))
            printf("\n");
      }
      printf(")\n");
   }
   system("pause");
   return(0);
}
