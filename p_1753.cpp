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
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int q[70000],d[70000];
int main()
{
   int first=0;
   for (int i=1;i<=4;i++)
      for (int j=1;j<=4;j++)
      {
         char ch;
         cin>>ch;
         first=(first<<1)+(ch=='b');
      }
   int l,r;
   l=r=1,q[1]=first,d[first]=1;
   while (l<=r)
   {
      int x=q[l],time=d[x],a[5][5];
      for (int i=4;i;i--)
         for (int j=4;j;j--)
         {
            a[i][j]=x&1;
            x>>=1;
         }
      for (int i=1;i<=4;i++)
         for (int j=1;j<=4;j++)
         {
            a[i][j]=1-a[i][j];
            for (int k=0;k<4;k++)
            {
               int x0=i+c[k][0],y0=j+c[k][1];
               if (!x0 || x0==5 || !y0 || y0==5)
                  continue;
               a[x0][y0]=1-a[x0][y0];
            }
            int now=0;
            for (int x=1;x<=4;x++)
               for (int y=1;y<=4;y++)
                  now=(now<<1)+a[x][y];
            if (!d[now])
            {
               d[now]=time+1;
               q[++r]=now;
            }
            a[i][j]=1-a[i][j];
            for (int k=0;k<4;k++)
            {
               int x0=i+c[k][0],y0=j+c[k][1];
               if (!x0 || x0==5 || !y0 || y0==5)
                  continue;
               a[x0][y0]=1-a[x0][y0];
            }
         }
      l++;
   }
   int ans=min(d[0],d[65535])-1;
   if (ans==-1)
      printf("Impossible\n");
   else
      printf("%d\n",ans);
   system("pause");
   return(0);
}
