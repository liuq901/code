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
#define MAXN 40
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const double pi=acos(-1.0);
const double eps=1e-7;
int a[MAXN][MAXN];
int main()
{
   void init();
   ios::sync_with_stdio(false);
   init();
   int n;
   while (cin>>n)
   {
      for (int i=1;i<=n;i++)
      {
         for (int j=1;j<i;j++)
            cout<<a[i][j]<<" ";
         cout<<a[i][i]<<endl;
      }
      cout<<endl;
   }
   system("pause");
   return(0);
}
void init()
{
   for (int i=1;i<=30;i++)
   {
      a[i][1]=a[i][i]=1;
      for (int j=2;j<i;j++)
         a[i][j]=a[i-1][j-1]+a[i-1][j];
   }
}
