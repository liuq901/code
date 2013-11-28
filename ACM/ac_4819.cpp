#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <complex>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#define SQR(x) ((x)*(x))
using namespace std;
const int inf=(1<<30)-1;
map <string,int> s;
char S[110],buf[100010];
int T,m,n,p[20],can[20][60];
int main()
{
   bool check(int x);
   while (1)
   {
      scanf("%d%d",&n,&m);
      T=n+m+1;
      if (!n && !m)
         break;
      s.clear();
      for (int i=1;i<=n;i++)
      {
         scanf("%s%d",S,&p[i]);
         s[S]=i;
         can[i][0]=0;
      }
      gets(buf);
      for (int i=1;i<=m;i++)
      {
      	gets(buf);
      	stringstream sin(buf);
      	string S;
      	while (sin>>S)
         {
            int p=s[S];
            can[p][++can[p][0]]=i;
         }
      }
      int ans=0;
      for (int i=(1<<n)-1;i>=0;i--)
      {
         int x=i,t=0;
         while (x)
         {
            t+=x&1;
            x>>=1;
         }
         if (t<=ans)
            continue;
         if (check(i))
            ans=t;
      }
      static int id=0;
      printf("Case #%d: %d\n",++id,ans);
   }
   system("pause");
   return(0);
}
int tot,b[100],a[10000][3];
bool check(int x)
{
   void add(int,int,int);
   bool build();
   int dinic(int,int);
   memset(b,0,sizeof(b));
   int ans=0;
   tot=1;
   for (int i=1;i<=n;i++)
      if (x>>i-1&1)
      {
         ans+=p[i];
         add(0,i,p[i]);
         for (int j=1;j<=can[i][0];j++)
         {
            int x=can[i][j];
            add(i,x+n,1);
         }
      }
   for (int i=1;i<=m;i++)
      add(i+n,T,1);
   while (build())
      ans-=dinic(0,inf);
   return(!ans);
}
void add(int x,int y,int c)
{
   a[++tot][0]=y,a[tot][1]=c,a[tot][2]=b[x],b[x]=tot;
   a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],b[y]=tot;
}
int d[100],q[100];
bool build()
{
   int l,r;
   memset(d,0,sizeof(d));
   l=r=1,q[1]=0,d[0]=1;
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
