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
const int c[4][2]={{0,-1},{1,0},{0,1},{-1,0}};
bool a[33][33][4];
int d[33][33],q[1000][2];
int main()
{
   while (1)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      if (!n && !m)
         break;
      for (int i=1;i<m;i++)
      {
         for (int j=1;j<n;j++)
         {
            int x;
            scanf("%d",&x);
            a[i][j][2]=a[i][j+1][0]=x==0;
         }
         for (int j=1;j<=n;j++)
         {
            int x;
            scanf("%d",&x);
            a[i][j][1]=a[i+1][j][3]=x==0;
         }
      }
      for (int j=1;j<n;j++)
      {
         int x;
         scanf("%d",&x);
         a[m][j][2]=a[m][j+1][0]=x==0;
      }
      for (int i=1;i<=n;i++)
         a[1][i][3]=a[m][i][1]=false;
      for (int i=1;i<=m;i++)
         a[i][1][0]=a[i][n][2]=false;
      memset(d,0,sizeof(d));
      int l,r;
      l=r=1,q[1][0]=1,q[1][1]=1;
      d[1][1]=1;
      while (l<=r)
      {
         int x0=q[l][0],y0=q[l][1];
         for (int i=0;i<4;i++)
         {
            int x=x0+c[i][0],y=y0+c[i][1];
            if (!a[x0][y0][i] || d[x][y])
               continue;
            d[x][y]=d[x0][y0]+1;
            q[++r][0]=x,q[r][1]=y;
         }
         l++;
      }
      printf("%d\n",d[m][n]);
   }
   system("pause");
   return(0);
}
