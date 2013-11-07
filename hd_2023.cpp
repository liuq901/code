#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cstdarg>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iomanip>
#define SQR(x) ((x)*(x))
#define MAXN 60
#define MAXM 10
using namespace std;
typedef long long ll;
typedef long double ld;
const double pi=acos(-1.0);
const double eps=1e-7;
int main()
{
   int n,m;
   while (cin>>n>>m)
   {
      double ave[MAXN]={0},ans[MAXM]={0};
      int a[MAXN][MAXM];
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
         {
            cin>>a[i][j];
            ave[i]+=a[i][j];
            ans[j]+=a[i][j];
         }
      cout.precision(2);
      cout.setf(ios::fixed);
      for (int i=1;i<n;i++)
         cout<<ave[i]/m<<" ";
      cout<<ave[n]/m<<endl;
      for (int i=1;i<m;i++)
         cout<<ans[i]/n<<" ";
      cout<<ans[m]/n<<endl;
      int sum=0;
      for (int i=1;i<=n;i++)
      {
         bool flag=true;
         for (int j=1;j<=m;j++)
            if (a[i][j]<ans[j]/n)
            {
               flag=false;
               break;
            }
         sum+=flag;
      }
      cout<<sum<<endl<<endl;
   }
   system("pause");
   return(0);
}
