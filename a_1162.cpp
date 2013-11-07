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
int tot,b[1000],a[2600000][2];
double dist[2600000];
int main()
{
   void add(int,int,int,int);
   double spfa(int,int,int);
   while (1)
   {
      int n,m,S,T;
      scanf("%d%d",&n,&m);
      if (!n && !m)
         break;
      scanf("%d%d",&S,&T);
      tot=0;
      memset(b,0,sizeof(b));
      for (int i=1;i<=m;i++)
      {
         int x,y,d,c;
         scanf("%d%d%d%d",&x,&y,&d,&c);
         if (y==T)
         {
            int k=(x-1)*30+1;
            a[++tot][0]=0,a[tot][1]=b[k],dist[tot]=d,b[k]=tot;
         }
         if (x==T)
         {
            int k=(y-1)*30+1;
            a[++tot][0]=0,a[tot][1]=b[k],dist[tot]=d,b[k]=tot;
         }
         add(x,y,d,c);
         add(y,x,d,c);
      }
      S=(S-1)*30+1;
      double len=spfa(n,S,T);
      if (len>1e50)
         printf("unreachable\n");
      else
         printf("%.10lf\n",len);
   }
   system("pause");
   return(0);
}
void add(int x0,int y0,int d,int c)
{
   for (int i=1;i<=30;i++)
   {
      if (i>c)
         break;
      for (int j=i-1;j<=i+1;j++)
      {
         if (!j || j>30)
            continue;
         int x=(x0-1)*30+i,y=(y0-1)*30+j;
         a[++tot][0]=y,a[tot][1]=b[x],dist[tot]=double(d)/i,b[x]=tot;
      }
   }
}
double d[31][1000];
bool f[1000];
int q[1000];
double spfa(int n,int S,int T)
{
   int check(int,int);
   for (int i=1;i<=n;i++)
      for (int j=0;j<=n*30;j++)
         d[i][j]=1e100;
   memset(f,0,sizeof(f));
   int l,r,k=check(S,T);
   l=0,r=1,q[1]=S,d[k][S]=0,f[S]=true;
   while (l!=r)
   {
      l=l==950?1:l+1;
      int x=q[l];
      for (int i=b[x];i;i=a[i][1])
      {
         int y=a[i][0],k=check(y,T),t=check(x,T);
         for (int p=1;p<=n;p++)
         {
            if (p==k)
               continue;
            if (d[t][y]-d[p][x]-dist[i]>eps)
            {
               d[t][y]=d[p][x]+dist[i];
               if (!f[y])
               {
                  f[y]=true;
                  q[r=r==950?1:r+1]=y;
               }
            }
         }
      }
      f[x]=false;
   }
   double ans=1e100;
   for (int i=1;i<=n;i++)
      ans=min(ans,d[i][0]);
   return(ans);
}
int check(int x,int T)
{
   if (!x)
      return(T);
   return((x-1)/30+1);
}
