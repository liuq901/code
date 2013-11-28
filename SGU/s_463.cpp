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
const int c[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int n,m,a[110][110];
int main()
{
   int add(int,int,int,int);
   scanf("%d%d",&n,&m);
   for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
      {
         char ch;
         cin>>ch;
         a[i][j]=ch-'0';
      }
   int t=0,ans=0,x=0,y=0;
   scanf("%*c");
   while (1)
   {
      char ch;
      scanf("%c",&ch);
      if (!isalpha(ch))
         break;
      if (ch=='L')
         t=!t?3:t-1;
      else if (ch=='R')
         t=t==3?0:t+1;
      else
      {
         ans+=add(x,y,x+c[t][0],y+c[t][1]);
         x+=c[t][0],y+=c[t][1];
      }
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
int add(int x1,int y1,int x2,int y2)
{
   int calc(int,int);
   int ans=0;
   if (x1==x2)
   {
      if (y1>y2)
         swap(y1,y2);
      if (x1)
         ans+=calc(x2,y2);
      if (x1<n)
         ans+=calc(x2+1,y2);
   }
   else
   {
      if (x1>x2)
         swap(x1,x2);
      if (y2)
         ans+=calc(x2,y2);
      if (y2<m)
         ans+=calc(x2,y2+1);
   }
   return(ans);
}
int f[110][110];
int calc(int x,int y)
{
   if (f[x][y])
      return(a[x][y]>>1);
   f[x][y]=true;
   return(a[x][y]);
}
