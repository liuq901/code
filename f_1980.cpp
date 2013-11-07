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
#define MAXN 1010
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
int S,T,tot,b[20010],a[1000000][3];
int main()
{
   void add(int,int,int);
   bool build();
   int dinic(int,int);
   int test;
   scanf("%d",&test);
   for (int id=1;id<=test;id++)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      memset(b,0,sizeof(b));
      tot=1;
      S=0,T=n+m+1;
      ll ans=0;
      for (int i=1;i<=n;i++)
      {
         int k;
         scanf("%d",&k);
         for (int j=1;j<=k;j++)
         {
            int x;
            scanf("%d",&x);
            add(i,x+n,inf);
         }
         scanf("%d",&k);
         add(S,i,k);
         ans+=k;
      }
      for (int i=1;i<=m;i++)
      {
         int x;
         scanf("%d",&x);
         add(i+n,T,x);
      }
      while (build())
         ans-=dinic(S,inf);
      printf("Case %d: ",id);
      cout<<ans<<endl;
   }
   system("pause");
   return(0);
}
void add(int x,int y,int c)
{
   a[++tot][0]=y,a[tot][1]=c,a[tot][2]=b[x],b[x]=tot;
   a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],b[y]=tot;
}
int q[20010],d[20010];
bool build()
{
   int l,r;
   memset(d,0,sizeof(d));
   l=r=1,d[S]=1,q[1]=S;
   while (l<=r)
   {
      int x=q[l];
      for (int i=b[x];i;i=a[i][2])
      {
         int y=a[i][0];
         if (d[y] || !a[i][1])
            continue;
         d[y]=d[x]+1;
         q[++r]=y;
         if (y==T)
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
         return(flow);
   }
   if (k==flow)
      d[x]=-1;
   return(flow-k);
}
