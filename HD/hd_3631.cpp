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
#define MAXN 310
#define MAXM 1000010
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const double eps=1e-7;
const double pi=acos(-1.0);
int a[MAXN][MAXN],b[MAXN][MAXN],c[MAXN][MAXN],dist[MAXN][MAXN];
bool f[MAXN];
int main()
{
   void update(int,int);
   ios::sync_with_stdio(false);
   int id=0;
   while (1)
   {
      int n,m,q;
      scanf("%d%d%d",&n,&m,&q);
      if (!n && !m && !q)
         break;
      for (int i=0;i<n;i++)
         a[i][0]=b[i][0]=0;
      memset(c,63,sizeof(c));
      for (int i=1;i<=m;i++)
      {
         int x,y,z;
         scanf("%d%d%d",&x,&y,&z);
         if (c[x][y]==inf)
         {
            a[x][++a[x][0]]=y;
            b[y][++b[y][0]]=x;
         }
         c[x][y]=min(c[x][y],z);
      }
      if (++id!=1)
         printf("\n");
      printf("Case %d:\n",id);
      memset(dist,63,sizeof(dist));
      memset(f,0,sizeof(f));
      for (int i=1;i<=q;i++)
      {
         int order;
         scanf("%d",&order);
         if (!order)
         {
            int x;
            scanf("%d",&x);
            if (f[x])
            {
               printf("ERROR! At point %d\n",x);
               continue;
            }
            update(x,n);
            f[x]=true;
         }
         else
         {
            int x,y;
            scanf("%d%d",&x,&y);
            if (!f[x] || !f[y])
               printf("ERROR! At path %d to %d\n",x,y);
            else if (dist[x][y]==inf)
               printf("No such path\n");
            else
               printf("%d\n",dist[x][y]);
         }
      }
   }
   system("pause");
   return(0);
}
int q[MAXM];
void update(int x,int n)
{
   int l,r,d[MAXN][2];
   bool flag[MAXN]={0};
   memset(d,63,sizeof(d));
   l=r=1,q[1]=x;
   d[x][0]=d[x][1]=0;
   while (l<=r)
   {
      int x=q[l];
      for (int i=1;i<=a[x][0];i++)
      {
         int y=a[x][i];
         if (f[y] && d[x][0]+c[x][y]<d[y][0])
         {
            d[y][0]=d[x][0]+c[x][y];
            if (!flag[y])
            {
               flag[y]=true;
               q[++r]=y;
            }
         }
      }
      l++;
      flag[x]=false;
   }
   l=r=1,q[1]=x;
   while (l<=r)
   {
      int x=q[l];
      for (int i=1;i<=b[x][0];i++)
      {
         int y=b[x][i];
         if (f[y] && d[x][1]+c[y][x]<d[y][1])
         {
            d[y][1]=d[x][1]+c[y][x];
            if (!flag[y])
            {
               flag[y]=true;
               q[++r]=y;
            }
         }
      }
      l++;
      flag[x]=false;
   }
   for (int i=0;i<n;i++)
      for (int j=0;j<n;j++)
         dist[i][j]=min(dist[i][j],d[i][1]+d[j][0]);
}
