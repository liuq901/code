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
using namespace std;
typedef long long ll;
const int c[8][2]={{1,3},{1,-3},{3,1},{3,-1},{-1,3},{-1,-3},{-3,1},{-3,-1}};
const int inf=1<<30;
int tot,S,T,b[1000],rank[1000][2],a[50000][3];
int num[40][40],value[40][40],color[40][40],edge[40][40];
bool first[40][40];
pair <int,int> out[1000];
int main()
{
   void add(int,int,int);
   bool build();
   int dinic(int,int);
   int test;
   scanf("%d",&test);
   while (test--)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      tot=0;
      S=0;
      T=n*m+1;
      ll ans=0;
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
         {
            num[i][j]=++tot;
            rank[tot][0]=i,rank[tot][1]=j;
            scanf("%d",&value[i][j]);
            ans+=value[i][j];
         }
      int p;
      memset(color,0,sizeof(color));
      memset(first,0,sizeof(first));
      scanf("%d",&p);
      for (int i=1;i<=p;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         color[x+1][y+1]=-1;
      }
      scanf("%d",&p);
      for (int i=1;i<=p;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         color[x+1][y+1]=1;
         first[x+1][y+1]=true;
      }
      memset(b,0,sizeof(b));
      tot=1;
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
         {
            if (color[i][j]==1)
            {
               ans-=value[i][j];
               continue;
            }
            if (value[i][j]<0 && color[i][j]!=-1)
            {
               ans-=value[i][j];
               color[i][j]=1;
               continue;
            }
            if (color[i][j]==-1)
               value[i][j]=inf;
            edge[i][j]=tot+1;
            if (i&1)
            {
               add(S,num[i][j],value[i][j]);
               for (int k=0;k<8;k++)
               {
                  int x=i+c[k][0],y=j+c[k][1];
                  if (x>0 && x<=n && y>0 && y<=m)
                     add(num[i][j],num[x][y],inf);
               }
            }
            else
               add(num[i][j],T,value[i][j]);
         }
      ll tmp=ans;
      while (build())
         ans-=dinic(S,inf);
      static int id=0;
      printf("Case %d: ",++id);
      int sum=0;
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
         {
            if (color[i][j]==1)
               continue;
            int t=a[edge[i][j]][1];
            a[edge[i][j]][1]=inf;
            if (!build())
               out[++sum]=make_pair(i,j);
            else
               a[edge[i][j]][1]=t;
         }
      while (sum>1 && value[out[sum].first][out[sum].second]==0)
         sum--;
      if (!sum)
      {
         int t=-inf,x,y;
         for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
               if (first[i][j])
                  continue;
               if (value[i][j]>t)
               {
                  t=value[i][j];
                  x=i,y=j;
               }
            }
         out[++sum]=make_pair(x,y);
         ans+=value[x][y];
      }
      cout<<ans<<endl;
      for (int i=1;i<=sum;i++)
         printf("%d %d\n",out[i].first-1,out[i].second-1);
   }
   system("pause");
   return(0);
}
void add(int x,int y,int z)
{
   a[++tot][0]=y,a[tot][1]=z,a[tot][2]=b[x],b[x]=tot;
   a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],b[y]=tot;
}
int q[1000],d[1000];
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
