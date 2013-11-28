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
#define MAXN 101000
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const double eps=1e-7;
const double pi=acos(-1.0);
pair <int,int> a[MAXN];
int limit,c[MAXN];
int main()
{
   int find(int);
   ios::sync_with_stdio(false);
   int n;
   while (cin>>n>>n>>n)
   {
      for (int i=0;i<n;i++)
         cin>>a[i].first>>a[i].second;
      sort(a,a+n);
      int ans=0;
      memset(c,0,sizeof(c));
      for (int i=0;i<n;i++)
      {
         int k=find(a[i].second);
         limit=max(limit,k+1);
         c[k+1]=max(c[k+1],a[i].second);
         ans=max(ans,k+1);
      }
      cout<<ans<<endl;
   }
   system("pause");
   return(0);
}
int find(int value)
{
   int l,r,ans;
   l=1,r=limit,ans=0;
   while (l<=r)
   {
      int mid=l+r>>1;
      if (c[mid]>value)
         ans=mid,l=mid+1;
      else 
         r=mid-1;
   }
   return(ans);
}
