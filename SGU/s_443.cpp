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
int main()
{
   void init();
   int calc(int);
   init();
   int a,b;
   scanf("%d%d",&a,&b);
   printf("%s\n",calc(a)>calc(b)?"a":"b");
   system("pause");
   return(0);
}
int a[1000010];
bool f[1000010];
void init()
{
   for (int i=2;i<=1000;i++)
   {
      if (f[i])
         continue;
      for (int j=i;i*j<=1000000;j++)
         f[i*j]=true;
   }
   for (int i=2;i<=1000000;i++)
      if (!f[i])
         a[++a[0]]=i;
}
int calc(int x)
{
   int t=-1,sum=0;
   for (int i=a[0];i;i--)
   {
      if (x%a[i])
         continue;
      t==-1?t=a[i]:sum+=a[i];
   }
   return(t-sum);
}
