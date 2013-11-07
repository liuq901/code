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
bool server[30];
int value[30],open[30],a[30][30];
vector <pair <int,int> > b[30];
int main()
{
   bool on(int,int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n,T,k,S;
      scanf("%d%d%d%d",&n,&T,&k,&S);
      memset(server,0,sizeof(server));
      for (int i=1;i<=k;i++)
      {
         int x;
         scanf("%d",&x);
         server[x]=true;
      }
      for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
      for (int i=1;i<=n;i++)
      {
         int m;
         scanf("%d",&m);
         b[i].resize(m);
         for (int j=0;j<m;j++)
            scanf("%d%d",&b[i][j].first,&b[i][j].second);
      }
      int m;
      scanf("%d",&m);
      memset(open,63,sizeof(open));
      for (int i=1;i<=m;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         open[y]=x;
      }
      memset(value,0,sizeof(value));
      for (int i=1;i<=T;i++)
      {
         for (int j=1;j<=n;j++)
         {
            if (server[j] || !on(i,j) || i<open[j])
               continue;
            int now=0;
            for (int k=1;k<=n;k++)
               if (server[k] && on(i,k))
                  now+=a[j][k];
            value[j]+=now;
         }
         for (int j=1;j<=n;j++)
            if (value[j]>=S)
               server[j]=true;
      }
      for (int i=1;i<=n;i++)
      {
         if (server[i])
         {
            printf("100%%\n");
            continue;
         }
         printf("%d%%\n",value[i]*100/S);
      }
   }
   system("pause");
   return(0);
}
bool on(int time,int pos)
{
   int n=b[pos].size();
   for (int i=0;i<n;i++)
      if (b[pos][i].first<=time && time<b[pos][i].second)
         return(true);
   return(false);
}
