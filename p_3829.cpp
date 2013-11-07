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
struct state
{
   int time,num,pos;
};
bool operator <(state a,state b)
{
   return(a.time<b.time);
}
state b[60];
int ans[60][2],a[40][40];
bool f[40][40];
int main()
{
   while (1)
   {
      int n,m,q;
      scanf("%d%d%d",&n,&m,&q);
      if (!n && !m && !q)
         break;
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
      for (int i=1;i<=q;i++)
      {
         int x,y;
         scanf("%d:%d%d",&x,&y,&b[i].num);
         b[i].time=x*60+y,b[i].pos=i;
      }
      sort(b+1,b+q+1);
      memset(f,0,sizeof(f));
      for (int p=1;p<=q;p++)
      {
         int num=b[p].num,pos=b[p].pos,mi=-inf,x,y;
         for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
               if (j+num-1>m)
                  break;
               if (a[i][j]<=mi)
                  continue;
               bool flag=true;
               for (int k=1;k<=num;k++)
                  if (f[i][j+k-1])
                  {
                     flag=false;
                     break;
                  }
               if (flag)
                  mi=a[i][j],x=i,y=j;
            }
         if (mi!=-inf)
         {
            for (int i=1;i<=num;i++)
               f[x][y+i-1]=true;
            ans[pos][0]=x,ans[pos][1]=y;
         }
         else
         {
            for (int i=1;i<=n;i++)
               for (int j=1;j<=m;j++)
                  if (!f[i][j] && a[i][j]>mi)
                     mi=a[i][j],x=i,y=j;
            if (mi!=-inf)
            {
               ans[pos][0]=x,ans[pos][1]=y;
               f[x][y]=true;
            }
            else
               ans[pos][0]=-1;
         }
      }
      for (int i=1;i<=q;i++)
      {
         if (ans[i][0]==-1)
         {
            printf("-1\n");
            continue;
         }
         printf("%d %d\n",ans[i][0],ans[i][1]);
      }
   }
   system("pause");
   return(0);
}

