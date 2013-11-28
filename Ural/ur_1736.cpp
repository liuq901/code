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
#define MAXN 50010
#define MAXM 1000010
using namespace std;
typedef long long ll;
typedef long double ld;
const double pi=acos(-1.0);
const double eps=1e-7;
const int inf=1061109567;
int S,T,tot=1,b[MAXN],a[MAXM][3];
int main()
{
   void add(int,int,int);
   bool build();
   int dinic(int,int);
   int n;
   scanf("%d",&n);
   S=0,T=n*n+n+1;
   int limit=n*n,p=0;
   for (int i=1;i<=n;i++)
      for (int j=i+1;j<=n;j++)
      {
         p++;
         add(p,limit+i,3);
         add(p,limit+j,3);
         add(S,p,3);
      }
   for (int i=1;i<=n;i++)
   {
      int x;
      scanf("%d",&x);
      add(limit+i,T,x);
   }
   int ans=0;
   while (build())
      ans+=dinic(S,inf);
   if (ans!=3*n*(n-1)>>1)
      printf("INCORRECT\n");
   else
   {
      printf("CORRECT\n");
      for (int i=1;i<=p;i++)
      {
         int x,y,flow;
         x=y=0;
         for (int j=b[i];j;j=a[j][2])
            if (a[j][0]>limit)
            {
               if (x)
               {
                  y=a[j][0]-limit;
                  break;
               }
               x=a[j][0]-limit;
               flow=3-a[j][1];
            }
         string s;
         switch (flow)
         {
         case 0:
            s="<";
            break;
         case 1:
            s="<=";
            break;
         case 2:
            s=">=";
            break;
         case 3:
            s=">";
            break;
         }
         printf("%d %s %d\n",x,s.c_str(),y);
      }
   }
   system("pause");
   return(0);
}
void add(int x,int y,int c)
{
   a[++tot][0]=y,a[tot][1]=c,a[tot][2]=b[x],b[x]=tot;
   a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],b[y]=tot;
}
int q[MAXN],d[MAXN];
bool build()
{
   int l,r;
   memset(d,0,sizeof(d));
   l=r=1;
   q[1]=S,d[S]=1;
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
