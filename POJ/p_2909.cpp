#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
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
#define MAXN 33010
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=(1<<30)-1;
const double eps=1e-7;
const double pi=acos(-1);
int ans[MAXN];
int main()
{
   void init();
   ios::sync_with_stdio(false);
   init();
   while (1)
   {
      int n;
      cin>>n;
      if (!n)
         break;
      cout<<ans[n]<<endl;
   }
   system("pause");
   return(0);
}
void init()
{
   int a[MAXN];
   bool f[MAXN]={0};
   f[1]=true;
   for (int i=2;i<=33000;i++)
   {
      if (f[i])
         continue;
      for (int j=i;i*j<=33000;j++)
         f[i*j]=true;
   }
   a[0]=0;
   for (int i=2;i<=33000;i++)
      if (!f[i])
         a[++a[0]]=i;
   for (int i=1;i<=a[0];i++)
      for (int j=i;j<=a[0];j++)
         if (a[i]+a[j]<=33000)
            ans[a[i]+a[j]]++;
}
