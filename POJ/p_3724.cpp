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
double p,x[30],y[30];
int n,now[20],ans[20];
int main()
{
   void search(int,int);
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%lf%lf",&x[i],&y[i]);
   p=1e100;
   search(1,1);
   for (int i=1;i<=10;i++)
      printf("%d\n",ans[i]);
   system("pause");
   return(0);
}
void search(int dep,int value)
{
   void check();
   if (dep==11)
   {
      check();
      return;
   }
   for (int i=value;i<=10;i++)
   {
      now[dep]=i;
      search(dep+1,i);
   }
}
void check()
{
   double sum=0;
   for (int i=1;i<=n;i++)
   {
      double tmp=0;
      for (int j=1;j<=10;j++)
         tmp+=exp(x[i]*now[j]);
      sum+=fabs(y[i]-tmp);
   }
   if (sum<p)
   {
      p=sum;
      memcpy(ans,now,sizeof(now));
   }
}
