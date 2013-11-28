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
#define MAXN 1010
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex <double> cp;
const double eps=1e-7;
const double pi=acos(-1);
const int c[8][2]={{-1,2},{-1,-2},{1,2},{1,-2},{2,-1},{2,1},{-2,-1},{-2,1}};
int main()
{
   bool check(int,int);
   ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while (t--)
   {
      int n,x1,y1,x2,y2;
      cin>>n>>x1>>y1>>x2>>y2;
      int f[301][301]={0};
      queue <pair <int,int> > q;
      f[x1][y1]=1;
      q.push(make_pair(x1,y1));
      while (1)
      {
         int x0=q.front().first,y0=q.front().second;
         if (x0==x2 && y0==y2)
         {
            cout<<f[x0][y0]-1<<endl;
            break;
         }
         for (int i=0;i<8;i++)
         {
            int x=x0+c[i][0],y=y0+c[i][1];
            if (!check(x,n) || !check(y,n) || f[x][y])
               continue;
            f[x][y]=f[x0][y0]+1;
            q.push(make_pair(x,y));
         }
         q.pop();
      }
   }
   system("pause");
   return(0);
}
bool check(int x,int limit)
{
   return(x>=0 && x<limit);
}
