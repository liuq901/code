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
#define MAXN 60
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
struct TroytownKeeper
{
   int limeLiters(vector <string> a)
   {
      p=a;
      n=a.size(),m=a[0].size();
      memset(f,0,sizeof(f));
      ans=0;
      for (int i=0;i<n;i++)
      {
         if (a[i][0]=='#')
            ans++;
         else if (!f[i][0])
            floodfill(i,0);
         if (a[i][m-1]=='#')
            ans++;
         else if (!f[i][m-1])
            floodfill(i,m-1);
      }
      for (int i=0;i<m;i++)
      {
         if (a[0][i]=='#')
            ans++;
         else if (!f[0][i])
            floodfill(0,i);
         if (a[n-1][i]=='#')
            ans++;
         else if (!f[n-1][i])
            floodfill(n-1,i);
      }
      return(ans);
   }
private:
   int n,m,ans;
   bool f[MAXN][MAXN];
   vector <string> p;
   void floodfill(int x0,int y0)
   {
      f[x0][y0]=true;
      for (int i=0;i<4;i++)
      {
         int x=x0+c[i][0],y=y0+c[i][1];
         if (x<0 || x==n || y<0 || y==m || f[x][y])
            continue;
         if (p[x][y]=='#')
            ans++;
         else
            floodfill(x,y);
      }
   }
};
int main()
{
   int n;
   scanf("%d",&n);
   vector <string> a;
   a.resize(n);
   for (int i=0;i<n;i++)
      cin>>a[i];
   TroytownKeeper p;
   printf("%d\n",p.limeLiters(a));
   system("pause");
   return(0);
}
