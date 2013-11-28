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
int p[210],a[210][210],q[50000][2];
bool f[210][210];
int main()
{
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
         scanf("%d",&a[i][j]);
   int m;
   scanf("%d",&m);
   for (int i=1;i<=m;i++)
      scanf("%d",&p[i]);
   int l,r;
   l=r=1,q[1][0]=1,q[1][1]=0,f[1][0]=true;
   while (l<=r)
   {
      int x=q[l][0],t=q[l][1];
      if (t==m)
         break;
      for (int i=1;i<=n;i++)
         if (!f[i][t+1] && a[x][i]==p[t+1])
         {
            f[i][t+1]=true;
            q[++r][0]=i,q[r][1]=t+1;
         }
      l++;
   }
   p[0]=0;
   for (int i=1;i<=n;i++)
      if (f[i][m])
         p[++p[0]]=i;
   printf("%d\n",p[0]);
   for (int i=1;i<=p[0];i++)
      printf("%d%c",p[i],i==p[0]?'\n':' ');
   system("pause");
   return(0);
}
