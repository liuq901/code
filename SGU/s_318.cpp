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
int f[110];
bitset <110> a[110];
int main()
{
   int find(int);
   int n,m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=n;i++)
      f[i]=i;
   for (int i=1;i<=m;i++)
   {
      int k;
      scanf("%d",&k);
      for (int j=1;j<=k;j++)
      {
         int x;
         scanf("%d",&x);
         a[x].set(i);
      }
   }
   for (int i=1;i<=n;i++)
      for (int j=i+1;j<=n;j++)
         if (a[i]==a[j])
         {
            int x=find(i),y=find(j);
            f[x]=y;
         }
   int ans=0;
   for (int i=1;i<=n;i++)
      ans+=i==find(i) && a[i].any();
   printf("%d\n",ans);
   system("pause");
   return(0);
}
int find(int x)
{
   if (x!=f[x])
      f[x]=find(f[x]);
   return(f[x]);
}
