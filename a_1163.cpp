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
bool f[510];
int b[510],c[510],d[510],Link[510],a[1000000][2];
int main()
{
   int gcd(int,int);
   bool hungary(int);
   while (1)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      if (!n && !m)
         break;
      for (int i=1;i<=n;i++)
         scanf("%d",&c[i]);
      for (int i=1;i<=m;i++)
         scanf("%d",&d[i]);
      memset(b,0,sizeof(b));
      int t=0;
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
         {
            int x=gcd(c[i],d[j]);
            if (x>1)
               a[++t][0]=j,a[t][1]=b[i],b[i]=t;
         }
      memset(Link,0,sizeof(Link));
      int ans=0;
      for (int i=1;i<=n;i++)
      {
         memset(f,0,sizeof(f));
         ans+=hungary(i);
      }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
int gcd(int a,int b)
{
   return(b?gcd(b,a%b):a);
}
bool hungary(int x)
{
   if (!x)
      return(true);
   for (int i=b[x];i;i=a[i][1])
   {
      int y=a[i][0];
      if (f[y])
         continue;
      f[y]=true;
      if (hungary(Link[y]))
      {
         Link[y]=x;
         return(true);
      }
   }
   return(false);
}
