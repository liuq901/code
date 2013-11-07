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
struct state
{
   int value,pos;
};
bool operator <(state a,state b)
{
   return(a.value<b.value);
}
bitset <10000010> S;
int n,ans[5010],s[10010];
state a[5010];
int main()
{
   int calc(int);
   int k;
   scanf("%d%d",&n,&k);
   for (int i=1;i<=k;i++)
   {
      scanf("%d",&a[i].value);
      a[i].pos=i;
   }
   for (int i=0;i<10000;i++)
      s[i]=i/1000+i/100%10+i/10%10+i%10;
   sort(a+1,a+k+1);
   int m=0,t=1;
   for (int i=1;i<=n;i++)
   {
      if (!S[i])
      {
         m++;
         while (t<=k && a[t].value==m)
         {
            ans[a[t].pos]=i;
            t++;
         }
      }
      S[i+s[i/10000]+s[i%10000]]=1;
   }
   printf("%d\n",m);
   for (int i=1;i<k;i++)
      printf("%d ",ans[i]);
   printf("%d\n",ans[k]);
   system("pause");
   return(0);
}
