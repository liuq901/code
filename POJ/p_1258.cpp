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
int n,tot,b[110],a[10010][3];
int main()
{
   void add(int,int,int);
   int prim();
   while (scanf("%d",&n)!=EOF)
   {
      memset(b,0,sizeof(b));
      tot=0;
      for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
         {
            int x;
            scanf("%d",&x);
            add(i,j,x);
         }
      printf("%d\n",prim());
   }
   system("pause");
   return(0);
}
void add(int x,int y,int c)
{
   a[++tot][0]=x,a[tot][1]=c,a[tot][2]=b[y],b[y]=tot;
}
int cost[110];
bool f[110];
int prim()
{
   memset(cost,63,sizeof(cost));
   memset(f,0,sizeof(f));
   cost[1]=0,cost[0]=inf;
   int ans=0;
   for (int i=1;i<=n;i++)
   {
      int k=0;
      for (int j=1;j<=n;j++)
         if (!f[j] && cost[j]<cost[k])
            k=j;
      ans+=cost[k];
      f[k]=true;
      for (int i=b[k];i;i=a[i][2])
      {
         int y=a[i][0];
         cost[y]=min(cost[y],a[i][1]);
      }
   }
   return(ans);
}
