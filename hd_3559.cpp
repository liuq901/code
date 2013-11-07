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
#define MAXN 10
#define MAXM 1000010
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
int d,x[MAXN],y[MAXN],q[MAXM];
bool vis[MAXM];
double f[MAXM];
int main()
{
   bool check(int,int);
   int n;
   while (scanf("%d%d",&n,&d)!=EOF)
   {
      for (int i=1;i<=5;i++)
         scanf("%d%d",&x[i],&y[i]);
      int tot=0,first=0;
      for (int i=1;i<=5;i++)
      {
         int x;
         scanf("%d",&x);
         first=(first<<3)+x;
         tot+=x;
      }
      first<<=3;
      bool a[MAXN][MAXN]={0};
      for (int i=1;i<=5;i++)
      {
         a[0][i]=true;
         for (int j=i+1;j<=5;j++)
            a[i][j]=a[j][i]=check(i,j);
      }
      int l,r;
      memset(vis,0,sizeof(vis));
      l=r=1,q[1]=first,vis[first]=true,f[first]=1.0;
      while (l<=r)
      {
         int x,pos,hp[MAXN];
         double prob;
         x=q[l],prob=f[x];
         pos=x&7,x>>=3;
         for (int i=5;i;i--)
            hp[i]=x&7,x>>=3;
         int now=0,sum=0;
         for (int i=1;i<=5;i++)
         {
            now+=hp[i];
            if (a[pos][i] && hp[i])
               sum++;
         }
         if (tot-now<=n)
            for (int i=1;i<=5;i++)
               if (a[pos][i] && hp[i])
               {
                  hp[i]--;
                  int y=0;
                  for (int j=1;j<=5;j++)
                     y=(y<<3)+hp[j];
                  y=(y<<3)+i;
                  if (vis[y])
                     f[y]+=prob*(1.0/sum);
                  else
                  {
                     vis[y]=true;
                     q[++r]=y;
                     f[y]=prob*(1.0/sum);
                  }
                  hp[i]++;
               }
         l++;
      }
      double ans[MAXN]={0};
      for (int i=1;i<=r;i++)
      {
         int x=q[i],pos,hp[MAXN];
         double now=f[x];
         pos=x&7,x>>=3;
         for (int i=5;i;i--)
            hp[i]=x&7,x>>=3;
         if (!hp[pos])
            ans[pos]+=now;
      }
      for (int i=1;i<5;i++)
         printf("%.3lf ",ans[i]);
      printf("%.3lf\n",ans[5]);
   }
   system("pause");
   return(0);
}
bool check(int i,int j)
{
   ll x1,y1,x2,y2,len;
   x1=x[i],y1=y[i],x2=x[j],y2=y[j],len=d;
   return(SQR(x1-x2)+SQR(y1-y2)<=SQR(len));
}
