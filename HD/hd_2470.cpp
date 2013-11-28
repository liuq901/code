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
int b[110],a[1000001][2];
bool f[110];
int main()
{
   int id=0;
   while (1)
   {
      int n,m,A,B;
      scanf("%d%d%d%d",&n,&m,&A,&B);
      if (!n && !m && !A && !B)
         break;
      memset(b,0,sizeof(b));
      for (int i=1;i<=m;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         x++,y++;
         a[i][0]=x,a[i][1]=b[y],b[y]=i;
         a[i+m][0]=y,a[i+m][1]=b[x],b[x]=i+m;
      }
      int ans=n;
      memset(f,0,sizeof(f));
      while (ans)
      {
         bool flag=true;
         for (int i=1;i<=n;i++)
         {
            if (f[i])
               continue;
            int sum=0;
            for (int j=b[i];j;j=a[j][1])
            {
               int y=a[j][0];
               if (!f[y])
                  sum++;
            }
            if (sum<A || ans-sum-1<B)
            {
               f[i]=true;
               flag=false;
               break;
            }
         }
         if (flag)
            break;
         ans--;
      }
      printf("Case #%d: %d\n",++id,ans);
   }
   system("pause");
   return(0);
}
