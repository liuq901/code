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
const double eps=1e-7;
const double pi=acos(-1.0);
struct RabbitNumber
{
   int a[2600];
   int theCount(int low,int high)
   {
      init();
      int ans=0;
      if (high==1000000000)
         ans++,high--;
      int l=low/1000000,r=high/1000000+1;
      for (int i=l;i<=r;i++)
         for (int j=1;j<=a[0];j++)
         {
            int x=i*1000000+a[j];
            if (x>=low && x<=high && calc(ll(x)*x)==SQR(calc(x)))
               ans++;
         }
      return(ans);
   }
   void init()
   {
      a[0]=0;
      for (int i=0;i<1000000;i++)
         if (calc(ll(i)*i)==SQR(calc(i)))
            a[++a[0]]=i;
   }
   int calc(ll x)
   {
      int s=0;
      while (x)
      {
         s+=x%10;
         x/=10;
      }
      return(s);
   }
};
int main()
{
   int a,b;
   scanf("%d%d",&a,&b);
   RabbitNumber p;
   printf("%d\n",p.theCount(a,b));
   system("pause");
   return(0);
}
