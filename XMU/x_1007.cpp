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
#define MAXN 1000010
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const double pi=acos(-1.0);
const double eps=1e-7;
const int mod=1000000007;
const int inf=1061109567;
int a[MAXM],b[MAXM],c[MAXN];
int main()
{
   void init(int *,string &);
   string s,t;
   cin>>s>>t;
   init(a,s),init(b,t);
   c[0]=a[0]+b[0];
   for (int i=1;i<=a[0];i++)
      for (int j=1;j<=b[0];j++)
      {
         c[i+j-1]+=a[i]*b[j];
         c[i+j]+=c[i+j-1]/10;
         c[i+j-1]%=10;
      }
   while (!c[c[0]] && c[0]>1)
      c[0]--;
   for (int i=c[0];i;i--)
      printf("%d",c[i]);
   printf("\n");
   system("pause");
   return(0);
}
void init(int *a,string &s)
{
   a[0]=s.size();
   for (int i=1;i<=a[0];i++)
      a[i]=s[a[0]-i]-'0';
}
