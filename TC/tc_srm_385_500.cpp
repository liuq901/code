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
#define MAXN 1010
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const int mod=835454957;
const double eps=1e-7;
const double pi=acos(-1.0);
struct BuildingAdvertise
{
   ll getMaxArea(vector <int> h,int n)
   {
      int m=h.size(),j=0;
      for (int i=0;i<n;i++)
      {
         R[i]=h[j];
         int s=(j+1)%m;
         h[j]=((h[j]^h[s])+13)%mod;
         j=s;
      }
      for (int i=0;i<n;i++)
         f[i][0]=R[i];
      for (int i=1;i<=16;i++)
         for (int j=0;j<n;j++)
         {
            if (j+(1<<i)-1==n)
               break;
            f[j][i]=min(f[j][i-1],f[j+(1<<i-1)][i-1]);
         }
      for (int i=0;i<n;i++)
      {
         left[i]=find(0,i-1,i);
         right[i]=find(i+1,n-1,i);
      }
      ll ans=0;
      for (int i=0;i<n;i++)
         ans=max(ans,ll(R[i])*(right[i]-left[i]+1));
      return(ans);
   }
private:
   int R[100000],left[100000],right[100000];
   static int f[100000][17];
   int find(int l,int r,int now)
   {
      int ans=now;
      while (l<=r)
      {
         int mid=l+r>>1;
         if (get(mid,now)==R[now])
         {
            ans=mid;
            if (r<now)
               r=mid-1;
            else
               l=mid+1;
         }
         else if (r<now)
            l=mid+1;
         else
            r=mid-1;
      }
      return(ans);
   }
   int get(int l,int r)
   {
      if (l>r)
         swap(l,r);
      int p=log(r-l+1);
      return(min(f[l][p],f[r-(1<<p)+1][p]));
   }
   int log(int x)
   {
      int ans=-1;
      while (x)
      {
         ans++;
         x>>=1;
      }
      return(ans);
   }
};
int BuildingAdvertise::f[100000][17];
int main()
{
   int m;
   scanf("%d",&m);
   vector <int> a;
   a.resize(m);
   for (int i=0;i<m;i++)
      scanf("%d",&a[i]);
   int n;
   scanf("%d",&n);
   BuildingAdvertise p;
   cout<<p.getMaxArea(a,n)<<endl;
   system("pause");
   return(0);
}
