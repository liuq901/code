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
int K,S,T,tot,route[110],b[110],a[10010][3];
int main()
{
   void add(int,int,int),spfa(),print(int);
   bool check(int);
   int n,m;
   scanf("%d%d%d",&n,&m,&K);
   for (int i=1;i<=m;i++)
   {
      int x,y,z;
      scanf("%d%d%d",&x,&y,&z);
      add(x,y,z),add(y,x,z);
   }
   scanf("%d%d",&S,&T);
   spfa();
   int l=1,r=inf,ans;
   while (l<=r)
   {
      int mid=l+r>>1;
      if (check(mid))
         ans=mid,r=mid-1;
      else
         l=mid+1;
   }
   tot=0;
   print(ans);
   printf("%d %d\n",ans,tot);
   for (int i=tot;i;i--)
      printf("%d%c",route[i],i==1?'\n':' ');
   system("pause");
   return(0);
}
void add(int x,int y,int z)
{
   a[++tot][0]=y,a[tot][1]=z,a[tot][2]=b[x],b[x]=tot;
}
int d[110];
bool f[110];
void spfa()
{
   queue <int> q;
   memset(d,63,sizeof(d));
   f[T]=true,d[T]=0,q.push(T);
   while (!q.empty())
   {
      int x=q.front();
      for (int i=b[x];i;i=a[i][2])
      {
         int y=a[i][0];
         if (d[x]+a[i][1]<d[y])
         {
            d[y]=d[x]+a[i][1];
            if (!f[y])
            {
               f[y]=true;
               q.push(y);
            }
         }
      }
      f[x]=false;
      q.pop();
   }
}
bool flag;
int sum,limit;
void print(int len)
{
   bool dfs(int,int);
   sum=0;
   limit=len;
   f[S]=flag=true;
   dfs(S,0);
}
bool check(int len)
{
   bool dfs(int,int);
   sum=0;
   limit=len;
   f[S]=true;
   dfs(S,0);
   return(sum>=K);
}
bool dfs(int x,int len)
{
   if (d[x]+len>limit)
      return(false);
   if (x==T)
   {
      if (flag && len==limit)
      {
         route[++tot]=x;
         return(true);
      }
      sum++;
      return(false);
   }
   for (int i=b[x];i;i=a[i][2])
   {
      int y=a[i][0];
      if (f[y])
         continue;
      f[y]=true;
      bool now=dfs(y,len+a[i][1]);
      if (flag && now)
      {
         route[++tot]=x;
         return(true);
      }
      f[y]=false;
      if (sum>=K)
         return(false);
   }
   return(false);
}
