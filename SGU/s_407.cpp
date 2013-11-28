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
const int mod=1000000;
const double eps=1e-7;
const double pi=acos(-1.0);
class bignum
{
   int len;
   int a[2000];
   friend bignum operator +(bignum,bignum);
   friend bignum operator *(bignum,int);
   int &operator [](int x)
   {
      return(a[x]);
   }
public:
   bignum()
   {
      memset(a,0,sizeof(a));
   }
   bignum(int x)
   {
      memset(a,0,sizeof(a));
      if (!x)
      {
         len=1;
         return;
      }
      len=0;
      while (x)
      {
         a[++len]=x%mod;
         x/=mod;
      }
   }
   void print()
   {
      printf("%d",a[len]);
      for (int i=len-1;i;i--)
         printf("%06d",a[i]);
      printf("\n");
   }
};
bignum operator +(bignum a,bignum b)
{
   bignum c;
   c.len=max(a.len,b.len);
   int x=0;
   for (int i=1;i<=c.len;i++)
   {
      c[i]=a[i]+b[i]+x;
      x=c[i]/mod;
      c[i]%=mod;
   }
   while (x)
   {
      c[++c.len]=x%mod;
      x/=mod;
   }
   return(c);
}
bignum operator *(bignum a,int b)
{
   bignum c;
   c.len=a.len;
   int x=0;
   for (int i=1;i<=c.len;i++)
   {
      c[i]=a[i]*b+x;
      x=c[i]/mod;
      c[i]%=mod;
   }
   while (x)
   {
      c[++c.len]=x%mod;
      x/=mod;
   }
   return(c);
}
bignum f[2],g[2];
int main()
{
   int n,m;
   scanf("%d%d",&n,&m);
   f[0]=1,f[1]=0,g[1]=1;
   for (int i=2;i<=m;i++)
   {
      f[i&1]=g[i-1&1]*n;
      g[i&1]=g[i-1&1]*2+f[i-1&1];
   }
   f[m&1].print();
   system("pause");
   return(0);
}
