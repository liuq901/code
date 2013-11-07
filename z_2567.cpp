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
#define MAXN 610
#define MAXM 2600000
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const double eps=1e-7;
const double pi=acos(-1.0);
int tot,S,T,b[MAXN],a[MAXM][3];
int main()
{
   void add(int,int,int),work(),print();
   ios::sync_with_stdio(false);
   int n,m,p;
   while (cin>>n>>m>>p)
   {
      memset(b,0,sizeof(b));
      tot=1;
      for (int i=1;i<=p;i++)
      {
         int x,y;
         cin>>x>>y;
         add(x,y+n,1);
      }
      int s,t;
      s=0,t=n+m+1,S=t+1,T=S+1;
      for (int i=1;i<=n;i++)
      {
         add(s,i,inf);
         add(S,i,2);
         add(s,T,2);
      }
      for (int i=1;i<=m;i++)
      {
         add(i+n,t,inf);
         add(S,t,2);
         add(i+n,T,2);
      }
      work();
      add(t,s,inf);
      work();
      print();
   }
   system("pause");
   return(0);
}
void add(int x,int y,int c)
{
   a[++tot][0]=y,a[tot][1]=c,a[tot][2]=b[x],b[x]=tot;
   a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],b[y]=tot;
}
void work()
{
   bool build();
   int dinic(int,int);
   while (build())
      dinic(S,inf);
}
int d[MAXN];
bool build()
{
   int l,r,q[MAXN];
   memset(d,0,sizeof(d));
   l=r=1,q[1]=S,d[S]=1;
   while (l<=r)
   {
      int x=q[l];
      for (int i=b[x];i;i=a[i][2])
      {
         int y=a[i][0];
         if (d[y] || !a[i][1])
            continue;
         d[y]=d[x]+1;
         if (y==T)
            return(true);
         q[++r]=y;
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
   for (int i=b[x];i;i=a[i][2])
   {
      int y=a[i][0];
      if (d[y]!=d[x]+1 || !a[i][1])
         continue;
      int t=dinic(y,min(k,a[i][1]));
      k-=t;
      a[i][1]-=t;
      a[i^1][1]+=t;
      if (!k)
         break;
   }
   if (k==flow)
      d[x]=-1;
   return(flow-k);
}
void print()
{
   for (int i=b[S];i;i=a[i][2])
      if (a[i][1])
      {
         cout<<-1<<endl;
         return;
      }
   cout<<a[tot][1]<<endl;
   int sum=0;
   for (int i=2;i<=tot;i+=2)
      if (!a[i][1])
      {
         cout<<i/2;
         if (++sum==a[tot][1])
            break;
         cout<<" ";
      }
   cout<<endl;
}
