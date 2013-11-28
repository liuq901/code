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
int S,T,tot=1,b[3000],a[1000000][3];
int main()
{
   void add(int,int,int);
   bool build();
   int dinic(int,int);
   int n,m;
   scanf("%d%d",&n,&m);
   int limit=0;
   for (int i=1;i<=n;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      y+=x-1;
      limit=max(limit,y);
      add(S,i,2);
      for (int j=x;j<=y;j++)
         add(i,j+n+1,1);
   }
   T=n+limit+26;
   for (int i=0;i<=limit;i++)
      add(i+n+1,T,m);
   int ans=0;
   while (build())
      ans+=dinic(S,inf);
   if (ans==n<<1)
   {
      printf("Yes\n");
      for (int i=1;i<=n;i++)
      {
         int x,y;
         x=y=0;
         for (int j=b[i];j;j=a[j][2])
         {
            if (a[j][1])
               continue;
            if (!x)
               x=a[j][0]-n-1;
            else
            {
               y=a[j][0]-n-1;
               break;
            }
         }
         if (x>y)
            swap(x,y);
         printf("%d %d\n",x,y);
      }
   }
   else
      printf("No\n");
   system("pause");
   return(0);
}
void add(int x,int y,int c)
{
   a[++tot][0]=y,a[tot][1]=c,a[tot][2]=b[x],b[x]=tot;
   a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],b[y]=tot;
}
int q[3000],d[3000];
bool build()
{
   memset(d,0,sizeof(d));
   int l,r;
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
