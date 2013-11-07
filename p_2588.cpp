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
const double eps=1e-5;
const double pi=acos(-1.0);
int S,T,a[MAXN][MAXN];
double x[MAXN],y[MAXN],r[MAXN];
int main()
{
   void add_edge(int,int);
   double dist(int,int);
   bool check();
   pair <double,double> find();
   ios::sync_with_stdio(false);
   int n;
   cin>>n;
   S=0,T=n+1;
   for (int i=S;i<=T;i++)
      a[i][0]=0;
   for (int i=1;i<=n;i++)
      cin>>x[i]>>y[i]>>r[i];
   for (int i=1;i<=n;i++)
   {
      if (r[i]-y[i]>eps)
         add_edge(T,i);
      if (r[i]+y[i]-1000>eps)
         add_edge(S,i);
      for (int j=i+1;j<=n;j++)
         if (r[i]+r[j]-dist(i,j)>eps)
            add_edge(i,j);
   }
   if (!check())
      cout<<"Bill will be bitten."<<endl;
   else
   {
      pair <double,double> ans=find();
      cout<<"Bill enters at (0.00, "<<setprecision(2)<<fixed<<ans.first<<") and leaves at (1000.00, "<<ans.second<<")."<<endl;
   }
   system("pause");
   return(0);
}
void add_edge(int x,int y)
{
   a[x][++a[x][0]]=y;
   a[y][++a[y][0]]=x;
}
double dist(int a,int b)
{
   return(sqrt(SQR(x[a]-x[b])+SQR(y[a]-y[b])));
}
int pos[MAXN];
bool check()
{
   int l,r,q[MAXN];
   bool f[MAXN]={0};
   l=r=1,q[1]=S,f[S]=true;
   while (l<=r)
   {
      int x=q[l];
      for (int i=1;i<=a[x][0];i++)
      {
         int y=a[x][i];
         if (f[y])
            continue;
         f[y]=true;
         q[++r]=y;
         if (y==T)
            return(false);
      }
      pos[l]=x;
      pos[0]=l;
      l++;
   }
   return(true);
}
pair <double,double> find()
{
   pair <double,double> ans(1000,1000);
   for (int i=1;i<=pos[0];i++)
   {
      if (pos[i]==S)
         continue;
      double X=x[pos[i]],Y=y[pos[i]],R=r[pos[i]];
      if (R-X>eps)
      {
         double t=sqrt(SQR(R)-SQR(X));
         ans.first=min(ans.first,Y-t);
      }
      if (R+X-1000>eps)
      {
         double t=sqrt(SQR(R)-SQR(1000-X));
         ans.second=min(ans.second,Y-t);
      }
   }
   return(ans);
}
