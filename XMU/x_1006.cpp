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
const double pi=acos(-1.0);
const double eps=1e-7;
const int mod=1000000007;
const int inf=1061109567;
class bignum
{
   int a[MAXN];
public:
   bignum()
   {
      memset(a,0,sizeof(a));
   }
   int &operator [](int x)
   {
      return(a[x]);
   }
};
bignum operator +(bignum a,bignum b)
{
   bignum c;
   c[0]=max(a[0],b[0]);
   int x=0;
   for (int i=1;i<=c[0];i++)
   {
      c[i]=a[i]+b[i]+x;
      x=c[i]/10;
      c[i]%=10;
   }
   c[++c[0]]=x;
   while (!c[c[0]] && c[0]>1)
      c[0]--;
   return(c);
}
istream &operator >>(istream &cin,bignum &a)
{
   string s;
   cin>>s;
   a[0]=s.size();
   for (int i=1;i<=a[0];i++)
      a[i]=s[a[0]-i]-'0';
   return(cin);
}
ostream &operator <<(ostream &cout,bignum a)
{
   for (int i=a[0];i;i--)
      cout<<a[i];
   return(cout);
}
int main()
{
   bignum a,b;
   cin>>a>>b;
   cout<<a+b<<endl;
   system("pause");
   return(0);
}
