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
int a[110],b[110];
int main()
{
   bool compare(int,int);
   int n,m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=n;i++)
      scanf("%d",&a[i]);
   for (int i=1;i<=m;i++)
      scanf("%d",&b[i]);
   sort(a+1,a+n+1,compare),sort(b+1,b+m+1,compare);
   int ans=inf;
   for (int k=0;k<=min(n,m);k++)
   {
      int sum=0;
      for (int i=k+1;i<=n;i++)
         sum+=a[i];
      for (int i=k+1;i<=m;i++)
         sum+=b[i]*k;
      ans=min(ans,sum);
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
bool compare(int x,int y)
{
   return(x>y);
}
