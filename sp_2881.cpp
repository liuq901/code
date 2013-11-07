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
map <string,int> a;
typedef map <string,int>::iterator data;
int ans[20001];
int main()
{
   while (1)
   {
      int n;
      scanf("%d%*d",&n);
      if (!n)
         break;
      a.clear();
      for (int i=1;i<=n;i++)
      {
         string s;
         cin>>s;
         a[s]++;
      }
      memset(ans,0,sizeof(ans));
      for (data k=a.begin();k!=a.end();k++)
         ans[k->second]++;
      for (int i=1;i<=n;i++)
         printf("%d\n",ans[i]);
   }
   system("pause");
   return(0);
}
