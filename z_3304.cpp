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
const int c[8][2]={{-1,0},{1,0},{0,-1},{0,1},{1,1},{1,-1},{-1,1},{-1,-1}};
int n,m,now,a[MAXN][MAXM];
int main()
{
   void floodfill(int,int,bool);
   ios::sync_with_stdio(false);
   int n,m;
   while (cin>>n>>m)
   {
      memset(a,-1,sizeof(a));
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
         {
            char ch;
            cin>>ch;
            a[i][j]=ch=='P';
         }
      for (int i=1;i<=n;i++)
      {
         if (!a[i][1])
            floodfill(i,1,false);
         if (!a[i][m])
            floodfill(i,m,false);
      }
      for (int i=1;i<=m;i++)
      {
         if (!a[1][i])
            floodfill(1,i,false);
         if (!a[n][i])
            floodfill(n,i,false);
      }
      for (int i=2;i<n;i++)
         for (int j=2;j<m;j++)
         {
            if (a[i][j]!=1)
               continue;
            int sum=0;
            for (int k=0;k<4;k++)
            {
               int x=i+c[k][0],y=j+c[k][1];
               if (a[x][y]!=2)
                  sum++;
            }
            if (sum==4)
               a[i][j]=3;
         }
      int ans=0;
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
            if (a[i][j]==1)
            {
               now=0;
               floodfill(i,j,true);
               ans=max(ans,now);
            }
      cout<<ans<<endl;
   }
   system("pause");
   return(0);
}
void floodfill(int x0,int y0,bool flag)
{
   a[x0][y0]=2;
   now++;
   int order=flag?8:4,state=flag?1:0;
   for (int i=0;i<order;i++)
   {
      int x=x0+c[i][0],y=y0+c[i][1];
      if (a[x][y]==state)
         floodfill(x,y,flag);
   }
}
