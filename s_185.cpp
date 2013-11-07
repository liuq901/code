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
int n,S,T,d[410],a[410][410],c[410][410];
bool f[410][410];
int main()
{
   void dijkstra(),print();
   bool build();
   int dinic(int,int);
   int m;
   scanf("%d%d",&n,&m);
   memset(a,63,sizeof(a));
   for (int i=1;i<=m;i++)
   {
      int x,y,z;
      scanf("%d%d%d",&x,&y,&z);
      a[x][y]=a[y][x]=z;
   }
   S=1,T=n;
   dijkstra();
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
      {
         c[i][j]=d[i]+a[i][j]==d[j];
         f[i][j]=c[i][j]==1;
      }
   int ans=0;
   while (build())
   {
      ans+=dinic(S,inf);
      if (ans>=2)
         break;
   }
   if (ans<2)
      printf("No solution\n");
   else
      print(),print();
   system("pause");
   return(0);
}
bool flag[410];
void dijkstra()
{
   memset(d,63,sizeof(d));
   d[S]=0,d[0]=inf;
   for (int i=1;i<=n;i++)
   {
      int k=0;
      for (int j=1;j<=n;j++)
         if (!flag[j] && d[j]<d[k])
            k=j;
      if (!k)
         break;
      flag[k]=true;
      for (int j=1;j<=n;j++)
         d[j]=min(d[j],d[k]+a[k][j]);
   }
}
void print()
{
   int x=S;
   while (x!=T)
   {
      printf("%d ",x);
      for (int i=1;i<=n;i++)
         if (!c[x][i] && f[x][i])
         {
            f[x][i]=false;
            x=i;
            break;
         }
   }
   printf("%d\n",T);
}
int q[410];
bool build()
{
   int l,r;
   l=r=1;
   memset(d,0,sizeof(d));
   q[1]=S,d[S]=1;
   while (l<=r)
   {
      int x=q[l];
      for (int i=1;i<=n;i++)
      {
         if (d[i] || !c[x][i])
            continue;
         q[++r]=i;
         d[i]=d[x]+1;
         if (i==T)
            return(true);
      }
      l++;
   }
   return(false);
}
int dinic(int x,int flow)
{
   if (x==T)
      return(flow);
   int k=flow;
   for (int i=1;i<=n;i++)
   {
      if (!c[x][i] || d[i]!=d[x]+1)
         continue;
      int t=dinic(i,min(k,c[x][i]));
      k-=t;
      c[x][i]-=t;
      c[i][x]+=t;
      if (!k)
         return(flow);
   }
   if (k==flow)
      d[x]=-1;
   return(flow-k);
}
