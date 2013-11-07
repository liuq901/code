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
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
int tot,pos[201],b[10000],vis[10000],d[10000][201],a[1000000][2],q[2000001][2];
bool f[10000][201];
int main()
{
   void add(int,int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      memset(b,0,sizeof(b));
      tot=0;
      while (n--)
      {
         int x,k;
         scanf("%d%d",&x,&k);
         while (k--)
         {
            int y;
            scanf("%d",&y);
            add(x,y);
         }
      }
      memset(f,0,sizeof(f));
      pos[0]=0;
      while (m--)
      {
         int k;
         scanf("%d",&k);
         while (k--)
         {
            int x;
            scanf("%d",&x);
            if (!f[x][0])
            {
               f[x][0]=true;
               pos[++pos[0]]=x;
            }
         }
      }
      memset(vis,0,sizeof(vis));
      int l,r;
      l=1,r=0;
      for (int i=1;i<=pos[0];i++)
      {
         q[++r][0]=pos[i],q[r][1]=i;
         d[pos[i]][i]=1;
         f[pos[i]][i]=true;
         vis[pos[i]]=1;
      }
      int point=inf,ans=inf;
      if (pos[0]==1)
         point=pos[1],ans=1;
      while (l<=r)
      {
         int x=q[l][0],order=q[l][1];
         if (d[x][order]==ans)
            break;
         for (int i=b[x];i;i=a[i][1])
         {
            int y=a[i][0];
            if (f[y][order])
               continue;
            f[y][order]=true;
            q[++r][0]=y,q[r][1]=order;
            d[y][order]=d[x][order]+1;
            vis[y]++;
            if (vis[y]==pos[0] && y<point)
               point=y,ans=d[y][order];
         }
         l++;
      }
      printf("%d %d\n",ans,point);
   }
   system("pause");
   return(0);
}
void add(int x,int y)
{
   a[++tot][0]=y,a[tot][1]=b[x],b[x]=tot;
}
