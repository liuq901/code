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
int n,S,T,tot,b[10010],a[2600000][3];
int main()
{
   void add(int,int,int),print(int);
   bool build();
   int dinic(int,int);
   int id=0;
   while (1)
   {
      int m;
      scanf("%d%d%*c",&m,&n);
      if (!m && !n)
         break;
      memset(b,0,sizeof(b));
      tot=1;
      for (int i=1;i<=n;i++)
      {
         while (1)
         {
            int x;
            char ch;
            scanf("%d%c",&x,&ch);
            add(i+n,x,1);
            if (ch=='\n')
               break;
         }
         if (i==1 || i==2)
            add(i,i+n,m);
         else
            add(i,i+n,1);
      }
      S=1,T=2+n;
      int ans=0;
      while (build())
         ans+=dinic(S,inf);
      printf("Case %d:\n",++id);
      if (ans!=m)
         printf("Impossible\n");
      else
         print(S);
      printf("\n");
   }
   system("pause");
   return(0);
}
void add(int x,int y,int c)
{
   a[++tot][0]=y,a[tot][1]=c,a[tot][2]=b[x],b[x]=tot;
   a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],b[y]=tot;
}
void print(int x)
{
   if (x==2)
   {
      printf("2\n");
      return;
   }
   if (x<=n)
   {
      print(x+n);
      return;
   }
   for (int i=b[x];i;i=a[i][2])
   {
      int y=a[i][0];
      if (!a[i][1] && y!=x-n)
      {
         printf("%d ",x-n);
         print(y);
      }
   }
}
int d[10010],q[10010];
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
