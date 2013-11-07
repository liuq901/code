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
int n,S,tot,b[1010],d[1010],a[1000010][3];
bool f[1010];
int main()
{
   void add(int,int,int),spfa();
   int T,m,D;
   while (scanf("%d%d%d",&T,&m,&D)!=EOF)
   {
      memset(b,0,sizeof(b));
      tot=n=0;
      for (int i=1;i<=T;i++)
      {
         int x,y,z;
         scanf("%d%d%d",&x,&y,&z);
         add(x,y,z);
         add(y,x,z);
         n=max(n,max(x,y));
      }
      for (int i=1;i<=m;i++)
      {
         int x;
         scanf("%d",&x);
         add(S,x,0);
      }
      spfa();
      int ans=inf;
      for (int i=1;i<=D;i++)
      {
         int x;
         scanf("%d",&x);
         ans=min(ans,d[x]);
      }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
void add(int x,int y,int z)
{
   a[++tot][0]=y,a[tot][1]=z,a[tot][2]=b[x],b[x]=tot;
}
int q[1000010];
void spfa()
{
   memset(d,63,sizeof(d));
   memset(f,0,sizeof(f));
   int l,r;
   l=0,r=1,q[1]=S,d[S]=0,f[S]=true;
   while (l!=r)
   {
      l++;
      if (l==1000000)
         l=1;
      int x=q[l];
      for (int i=b[x];i;i=a[i][2])
      {
         int y=a[i][0];
         if (d[x]+a[i][1]<d[y])
         {
            d[y]=d[x]+a[i][1];
            if (!f[y])
            {
               f[y]=true;
               r++;
               if (r==1000000)
                  r=1;
               q[r]=y;
            }
         }
      }
      f[x]=false;
   }
}
