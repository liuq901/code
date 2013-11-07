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
#include <string>
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
int S,T,n,b[310],remain[310],tb[310],tp[310],a[30000][3];
char color[310];
int main()
{
   void dijkstra(),print();
   int m;
   scanf("%d%d%d%d",&S,&T,&n,&m);
   for (int i=1;i<=n;i++)
   {
      cin>>color[i];
      scanf("%d%d%d",&remain[i],&tb[i],&tp[i]);
   }
   for (int i=1;i<=m;i++)
   {
      int x,y,z;
      scanf("%d%d%d",&x,&y,&z);
      a[i][0]=y,a[i][1]=z,a[i][2]=b[x],b[x]=i;
      a[i+m][0]=x,a[i+m][1]=z,a[i+m][2]=b[y],b[y]=i+m;
   }
   dijkstra();
   print();
   system("pause");
   return(0);
}
int ans,pre[310],dist[310];
bool f[310];
void dijkstra()
{
   int calc(int,int,int);
   fill_n(dist,n+1,inf);
   dist[S]=0;
   for (int i=1;i<=n;i++)
   {
      int k=0;
      for (int j=1;j<=n;j++)
         if (!f[j] && dist[j]<dist[k])
            k=j;
      if (!k)
         break;
      f[k]=true;
      for (int i=b[k];i;i=a[i][2])
      {
         int y=a[i][0];
         if (f[y])
            continue;
         int t=calc(dist[k],k,y);
         if (t==-1)
            continue;
         if (dist[k]+a[i][1]+t<dist[y])
         {
            dist[y]=dist[k]+a[i][1]+t;
            pre[y]=k;
         }
      }
   }
   ans=dist[T];
}
int calc(int now,int u,int v)
{
   char get_color(int,int);
   for (int i=0;i<=500;i++)
      if (get_color(now+i,u)==get_color(now+i,v))
         return(i);
   return(-1);
}
char get_color(int time,int x)
{
   if (time<remain[x])
      return(color[x]);
   time=(time-remain[x])%(tb[x]+tp[x]);
   if (color[x]=='B')
      return(time<tp[x]?'P':'B');
   else
      return(time<tb[x]?'B':'P');
}
int c[310];
void print()
{
   if (S==T)
   {
      printf("0\n%d\n",S);
      return;
   }
   if (!pre[T])
   {
      printf("0\n");
      return;
   }
   printf("%d\n",ans);
   for (int i=T;i!=S;i=pre[i])
      c[++c[0]]=i;
   printf("%d",S);
   for (int i=c[0];i;i--)
      printf(" %d",c[i]);
   printf("\n");
}
