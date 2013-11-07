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
const int inf=1061109567;
const double eps=1e-7;
const double pi=acos(-1.0);
ll f[41][3];
int main()
{
   void init();
   init();
   int n;
   while (cin>>n)
      cout<<f[n][0]+f[n][1]+f[n][2]<<endl;
   system("pause");
   return(0);
}
void init()
{
   f[1][0]=f[1][1]=f[1][2]=1;
   for (int i=2;i<=40;i++)
      for (int j=0;j<=2;j++)
         for (int k=0;k<=2;k++)
         {
            if (j==2 && k==2)
               continue;
            f[i][k]+=f[i-1][j];
         }
}
