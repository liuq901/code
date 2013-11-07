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
bool f[10010];
bitset <10010> p;
vector <int> a[10010];
int main()
{
   int n,m;
   scanf("%d%d",&n,&m);
   f[0]=true;
   for (int i=1;i<=n;i++)
   {
      int x;
      scanf("%d",&x);
      for (int j=m;j>=x;j--)
      {
         if (!f[j-x])
            continue;
         if (!f[j])
         {
            f[j]=true;
            a[j].push_back(x);
            for (int k=0;k<a[j-x].size();k++)
               a[j].push_back(a[j-x][k]);
         }
         else
         {
            p.reset();
            for (int k=0;k<a[j-x].size();k++)
               p.set(a[j-x][k]);
            for (int k=0;k<a[j].size();k++)
               if (p.test(a[j][k]))
                  a[0].push_back(a[j][k]);
            a[j]=a[0];
            a[0].clear();
         }
      }
   }
   printf("%d\n",a[m].size());
   for (int i=0;i<a[m].size();i++)
      printf("%d%c",a[m][i],i==a[m].size()-1?'\n':' ');
   system("pause");
   return(0);
}
