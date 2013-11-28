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
#define MAXN 210
#define MAXM 410
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const double eps=1e-5;
const double pi=acos(-1.0);
int X[MAXN],Y[MAXN];
int main()
{
   void init(int);
   bool check(double);
   ios::sync_with_stdio(false);
   while (1)
   {
      int n;
      cin>>n;
      if (!n)
         break;
      for (int i=1;i<=n;i++)
         cin>>X[i]>>Y[i];
      init(n);
      double l=0,r=10000;
      while (r-l>eps)
      {
         double mid=(l+r)/2;
         (check(mid)?l:r)=mid;
      }
      cout<<setprecision(3)<<fixed<<l<<endl;
   }
   system("pause");
   return(0);
}
double d[MAXM][MAXM];
int m;
void init(int n)
{
   double dist(int,int,int,int);
   int t=-1,x[MAXM],y[MAXM];
   for (int i=1;i<=n;i++)
   {
      x[++t]=X[i],y[t]=Y[i]-1;
      x[++t]=X[i],y[t]=Y[i]+1;
   }
   m=t;
   for (int i=0;i<=m;i++)
      for (int j=i+1;j<=m;j++)
         d[i][j]=d[j][i]=dist(x[i],y[i],x[j],y[j]);
}
double dist(int x1,int y1,int x2,int y2)
{
   return(sqrt(double(SQR(x1-x2)+SQR(y1-y2))));
}
int id,now,dfn[MAXM],pos[MAXM],a[MAXM][MAXM];
bool check(double len)
{
   void add_edge(int,int),tarjan(int);
   for (int i=0;i<=m;i++)
      a[i][0]=0;
   for (int i=0;i<=m;i++)
      for (int j=i+1;j<=m;j++)
         if (d[i][j]<len)
         {
            add_edge(i,j^1);
            add_edge(j,i^1);
         }
   memset(dfn,0,sizeof(dfn));
   id=now=0;
   for (int i=0;i<=m;i++)
      if (!dfn[i])
         tarjan(i);
   for (int i=0;i<=m;i++)
      if (pos[i]==pos[i^1])
         return(false);
   return(true);
}
void add_edge(int x,int y)
{
   a[x][++a[x][0]]=y;
}
int low[MAXM];
bool flag[MAXM];
stack <int> s;
void tarjan(int x)
{
   dfn[x]=low[x]=++id;
   s.push(x);
   flag[x]=true;
   for (int i=1;i<=a[x][0];i++)
   {
      int y=a[x][i];
      if (!dfn[y])
      {
         tarjan(y);
         low[x]=min(low[x],low[y]);
      }
      else if (flag[y])
         low[x]=min(low[x],dfn[y]);
   }
   if (low[x]==dfn[x])
   {
      now++;
      while (s.top()!=x)
      {
         int p=s.top();
         s.pop();
         pos[p]=now;
         flag[p]=false;
      }
      pos[x]=now,flag[x]=false;
      s.pop();
   }
}
