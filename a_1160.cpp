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
const int c[8][2]={{-1,0},{1,0},{0,-1},{0,1},{1,1},{1,-1},{-1,1},{-1,-1}};
int n,m;
bool a[60][60],f[60][60];
int main()
{
   void floodfill(int,int);
   while (1)
   {
      scanf("%d%d",&m,&n);
      if (!n && !m)
         break;
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
         {
            int x;
            scanf("%d",&a[i][j]);
         }
      memset(f,0,sizeof(f));
      int ans=0;
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
            if (a[i][j] && !f[i][j])
            {
               ans++;
               floodfill(i,j);
            }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
void floodfill(int x0,int y0)
{
   f[x0][y0]=true;
   for (int i=0;i<8;i++)
   {
      int x=x0+c[i][0],y=y0+c[i][1];
      if (!x || x>n || !y || y>m || f[x][y] || !a[x][y])
         continue;
      floodfill(x,y);
   }
}
