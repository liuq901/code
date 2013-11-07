#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
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
#define MAXN 30
#define MAXM 30
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=(1<<30)-1;
const double eps=1e-7;
const double pi=acos(-1);
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool f[MAXN][MAXM];
char Map[MAXN][MAXM];
int ans;
int main()
{
   void floodfill(int,int);
   ios::sync_with_stdio(false);
   while (1)
   {
      int n,m,x0,y0;
      cin>>m>>n;
      if (!m && !n)
         break;
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
         {
            cin>>Map[i][j];
            if (Map[i][j]=='@')
               x0=i,y0=j;
         }
      ans=0;
      memset(f,0,sizeof(f));
      for (int i=1;i<=n;i++)
         f[i][0]=f[i][m+1]=true;
      for (int i=1;i<=m;i++)
         f[0][i]=f[n+1][i]=true;
      floodfill(x0,y0);
      cout<<ans<<endl;
   }
   system("pause");
   return(0);
}
void floodfill(int x0,int y0)
{
   ans++;
   f[x0][y0]=true;
   for (int i=0;i<4;i++)
   {
      int x=x0+c[i][0],y=y0+c[i][1];
      if (f[x][y] || Map[x][y]=='#')
         continue;
      floodfill(x,y);
   }
}
