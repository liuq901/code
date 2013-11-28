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
#define MAXN 1010
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
struct state
{
   int x,y,z;
};
bool operator <(state a,state b)
{
   return(a.x>b.x || a.x==b.x && a.y>b.y || a.x==b.x && a.y==b.y && a.z<b.z);
}
int sum[MAXN];
state a[MAXN];
bool f[MAXN][MAXN];
int main()
{
   int n,s,p;
   while (scanf("%d%d%d",&n,&s,&p)!=EOF)
   {
      memset(f,0,sizeof(f));
      memset(sum,0,sizeof(sum));
      for (int i=1;i<=n;i++)
         for (int j=1;j<=s;j++)
         {
            int x;
            scanf("%d",&x);
            if (x)
            {
               f[j][i]=true;
               sum[i]++;
            }
         }
      memset(a,0,sizeof(a));
      for (int i=1;i<=s;i++)
      {
         for (int j=1;j<=n;j++)
            if (f[i][j])
            {
               a[i].x+=s-sum[j];
               a[i].y++;
            }
         a[i].z=i;
      }
      sort(a+1,a+s+1);
      int ans1,ans2;
      for (int i=1;i<=s;i++)
         if (a[i].z==p)
         {
            ans1=a[i].x;
            ans2=i;
            break;
         }
      printf("%d %d\n",ans1,ans2);
   }
   system("pause");
   return(0);
}
