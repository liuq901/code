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
struct FibonacciKnapsack
{
   int n;
   ll ans,sum,s[55],a[55],b[55],A[55],B[55];
   ll maximalCost(vector <string> items,string C)
   {
      n=items.size();
      for (int i=0;i<n;i++)
      {
         stringstream sin(items[i]);
         sin>>a[i]>>b[i];
      }
      for (int i=0;i<n;i++)
         for (int j=i+1;j<n;j++)
            if (a[i]<a[j] || a[i]==a[j] && b[i]<b[j])
               swap(a[i],a[j]),swap(b[i],b[j]);
      s[n]=0;
      for (int i=n-1;i>=0;i--)
         s[i]=s[i+1]+a[i];
      stringstream sin(C);
      ll cost;
      sin>>cost;
      ans=sum=0;
      search(cost,0,true);
      return(ans);
   }
   void search(ll w,ll dep,bool last)
   {
      if (dep==n)
      {
         ans=max(ans,sum);
         return;
      }
      if (w>=a[dep] && (last || a[dep]!=a[dep-1]))
      {
         sum+=b[dep];
         search(w-a[dep],dep+1,true);
         sum-=b[dep];
      }
      if (s[dep]>w)
         search(w,dep+1,false);
   }
};
int main()
{
   int n;
   scanf("%d",&n);
   vector <string> d;
   for (int i=1;i<=n;i++)
   {
      string s;
      getline(cin,s);
      d.push_back(s);
   }
   string s;
   cin>>s;
   FibonacciKnapsack p;
   cout<<p.maximalCost(d,s)<<endl;
   system("pause");
   return(0);
}
