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
int n,k,m,a[10010],b[100010];
ll s[100010],f[10001][101];
int main()
{
   int find(ll),calc(int,ll);
   while (1)
   {
      scanf("%d%d%d",&n,&k,&m);
      if (!n && !k && !m)
         break;
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      s[0]=0;
      for (int i=1;i<=m;i++)
      {
         scanf("%d",&b[i]);
         s[i]=s[i-1]+b[i];
      }
      memset(f,0,sizeof(f));
      for (int i=0;i<n;i++)
         for (int j=0;j<=k;j++)
         {
            if (j>i)
               break;
            ll x=f[i][j];
            int pos=find(x),now=a[i+1];
            if (pos==m+1)
               break;
            if (now<=s[pos]-x)
               f[i+1][j]=max(f[i+1][j],x+now);
            else
            {
               now-=s[pos]-x;
               int p=calc(pos,now);
               f[i+1][j]=max(f[i+1][j],s[p]);
            }
            if (j==k)
               continue;
            now=2*a[i+1];
            if (now<=s[pos]-x)
               f[i+1][j+1]=max(f[i+1][j+1],x+now);
            else
            {
               now-=s[pos]-x;
               int p=calc(pos,now);
               f[i+1][j+1]=max(f[i+1][j+1],s[p]);
            }
         }
      ll ans=0;
      for (int i=0;i<=n;i++)
         for (int j=0;j<=k;j++)
            ans=max(ans,f[i][j]);
      printf("%d\n",find(ans)-1);
   }
   system("pause");
   return(0);
}
int find(ll x)
{
   int l=1,r=m,ans=m+1;
   while (l<=r)
   {
      int mid=l+r>>1;
      if (s[mid]>x)
         ans=mid,r=mid-1;
      else
         l=mid+1;
   }
   return(ans);
}
int calc(int pos,ll x)
{
   int l=pos+1,r=m,ans=pos;
   while (l<=r)
   {
      int mid=l+r>>1;
      if (s[mid]-s[pos]<=x)
         ans=mid,l=mid+1;
      else
         r=mid-1;
   }
   return(ans);
}
