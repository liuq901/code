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
int a[110][110],b[110][110],c[110][110];
int main()
{
   int n,m,p;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
         scanf("%d",&a[i][j]);
   scanf("%*d%d",&p);
   for (int i=1;i<=m;i++)
      for (int j=1;j<=p;j++)
         scanf("%d",&b[i][j]);
   for (int i=1;i<=n;i++)
      for (int j=1;j<=p;j++)
         for (int k=1;k<=m;k++)
            c[i][j]+=a[i][k]*b[k][j];
   for (int i=1;i<=n;i++)
   {
      for (int j=1;j<p;j++)
         printf("%d ",c[i][j]);
      printf("%d\n",c[i][p]);
   }
   system("pause");
   return(0);
}
