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
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
ll ans;
int b[10001],a[20010][3];
int main()
{
   void floodfill(int,int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n;
      scanf("%d",&n);
      memset(b,0,sizeof(b));
      for (int i=1;i<n;i++)
      {
         int x,y,z;
         scanf("%d%d%d",&x,&y,&z);
         a[i][0]=y,a[i][1]=z,a[i][2]=b[x],b[x]=i;
         a[i+n][0]=x,a[i+n][1]=z,a[i+n][2]=b[y],b[y]=i+n;
      }
      ans=0;
      floodfill(0,-1);
      int point=n*(n-1)>>1;
      cout<<setprecision(10)<<fixed<<ld(ans)/point<<endl;
   }
   system("pause");
   return(0);
}
ll d[10001];
int pos[10001],sum[10001];
void floodfill(int x,int father)
{
   d[x]=0,sum[x]=1;
   for (int i=b[x];i;i=a[i][2])
   {
      int y=a[i][0];
      if (y==father)
         continue;
      floodfill(y,x);
      d[y]+=a[i][1]*sum[y];
      d[x]+=d[y],sum[x]+=sum[y];
   }
   pos[0]=0;
   for (int i=b[x];i;i=a[i][2])
   {
      int y=a[i][0];
      if (y==father)
         continue;
      pos[++pos[0]]=y;
   }
   ll now=d[pos[1]];
   int num=sum[pos[1]];
   for (int i=2;i<=pos[0];i++)
   {
      int y=pos[i];
      ans+=now*sum[y]+num*d[y];
      now+=d[y],num+=sum[y];
   }
   ans+=d[x];
}
