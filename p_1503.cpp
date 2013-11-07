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
int ans[10001],a[10001];
int main()
{
   while (1)
   {
      string s;
      cin>>s;
      int n=s.size();
      if (n==1 && s[0]=='0')
         break;
      memset(a,0,sizeof(a));
      for (int i=0;i<n;i++)
         a[n-i]=s[i]-'0';
      a[0]=n;
      ans[0]=max(ans[0],n);
      int x=0;
      for (int i=1;i<=ans[0];i++)
      {
         ans[i]+=a[i]+x;
         x=ans[i]/10;
         ans[i]%=10;
      }
      if (x)
         ans[++ans[0]]=x;
   }
   for (int i=ans[0];i;i--)
      printf("%d",ans[i]);
   printf("\n");
   system("pause");
   return(0);
}
