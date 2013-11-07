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
int a[50],f[50][50];
int main()
{
   bool comp(int,int);
   int T;
   scanf("%d",&T);
   a[0]=100;
   while (T--)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      sort(a+1,a+n+1,comp);
      memset(f,0,sizeof(f));
      for (int i=1;i<=n;i++)
         for (int j=1;j<=min(m,i);j++)
            for (int k=0;k<i;k++)
               f[i][j]=max(f[i][j],f[k][j-1]+SQR(a[k]-a[i]));
      printf("%d\n",f[n][m]);
   }
   system("pause");
   return(0);
}
bool comp(int x,int y)
{
   return(x>y);
}
