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
#define MAXN 1010
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex <double> cp;
const double eps=1e-7;
const double pi=acos(-1);
struct CircleMarket
{
   int makePurchases(vector <int> open,vector <int> close,int travel)
   {
      int n=open.size(),Max=0;
      for (int i=0;i<n;i++)
         Max=max(Max,close[i]);
      int t=0,now=0,ans=0;
      bool f[51]={0};
      while (t<=Max)
      {
         if (!f[now] && t>=open[now] && t<=close[now])
            ans++,f[now]=true;
         t+=travel,now++;
         if (now==n)
            now=0;
      }
      return(ans);
   }
};
int main()
{
   int n;
   scanf("%d",&n);
   vector <int> a,b;
   a.resize(n),b.resize(n);
   for (int i=0;i<n;i++)
      scanf("%d",&a[i]);
   for (int i=0;i<n;i++)
      scanf("%d",&b[i]);
   int x;
   scanf("%d",&x);
   CircleMarket p;
   printf("%d\n",p.makePurchases(a,b,x));
   system("pause");
   return(0);
}
