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
const double pi=acos(-1.0);
const double eps=1e-7;
int main()
{
   ios::sync_with_stdio(false);
   int n,m;
   while (cin>>n>>m)
   {
      if (!n && !m)
         break;
      set <int> a;
      for (int i=1;i<=n;i++)
      {
         int x;
         cin>>x;
         a.insert(x);
      }
      set <int>::iterator k;
      for (int i=1;i<=m;i++)
      {
         int x;
         cin>>x;
         k=a.find(x);
         if (k!=a.end())
            a.erase(k);
      }
      for (k=a.begin();k!=a.end();k++)
         cout<<*k<<" ";
      if (a.empty())
         cout<<"NULL";
      cout<<endl;
   }
   system("pause");
   return(0);
}
