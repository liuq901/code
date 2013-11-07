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
typedef map <int,int>::iterator data;
const int inf=1061109567;
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
map <int,int> s;
int S,T,tot,b[1010],a[2010][3];
int main()
{
   void add(int,int,int);
   int spfa(int);
   int test;
   scanf("%d",&test);
   while (test--)
   {
      int n,d;
      scanf("%d%d",&n,&d);
      s.clear();
      for (int i=1;i<=n;i++)
      {
         int x;
         scanf("%d",&x);
         s[x]=i;
      }
      tot=0;
      memset(b,0,sizeof(b));
      for (data k=s.begin();k!=s.end();k++)
      {
         data t=k;
         t++;
         if (t==s.end())
            T=k->second;
         else
         {
            int x=k->second,y=t->second;
            if (x>y)
               swap(x,y);
            add(x,y,d);
         }
      }
      S=s.begin()->second;
      if (S>T)
         swap(S,T);
      for (int i=1;i<n;i++)
         add(i+1,i,-1);
      static int id=0;
      printf("Case %d: %d\n",++id,spfa(n));
   }
   system("pause");
   return(0);
}
void add(int x,int y,int c)
{
   a[++tot][0]=y,a[tot][1]=c,a[tot][2]=b[x],b[x]=tot;
}
queue <int> q;
bool f[1010];
int d[1010],vis[1010];
int spfa(int limit)
{
   memset(d,63,sizeof(d));
   memset(vis,0,sizeof(vis));
   memset(f,0,sizeof(f));
   while (!q.empty())
      q.pop();
   q.push(S),d[S]=0,f[S]=true;
   while (!q.empty())
   {
      int x=q.front();
      for (int i=b[x];i;i=a[i][2])
      {
         int y=a[i][0];
         if (d[x]+a[i][1]<d[y])
         {
            d[y]=d[x]+a[i][1];
            vis[y]++;
            if (vis[y]>limit)
               return(-1);
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
   return(d[T]);
}
