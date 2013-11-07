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
int next[1010],e[5010][5];
bool f[1010];
int main()
{
   int n,m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=m;i++)
   {
      int x1,x2,y1,y2;
      char ch;
      scanf("%d%d%d%d %c",&x1,&y1,&x2,&y2,&ch);
      e[i][0]=min(x1,x2),e[i][1]=min(y1,y2),e[i][2]=max(x1,x2),e[i][3]=max(y1,y2),e[i][4]=ch=='b';
   }
   int ans=SQR(n);
   for (int i=1;i<=n;i++)
   {
      for (int j=0;j<=n;j++)
         next[j]=j+1;
      next[n+1]=n+1;
      memset(f,0,sizeof(f));
      for (int j=m;j;j--)
         if (i>=e[j][0] && i<=e[j][2])
            for (int k=e[j][1];k<=e[j][3];)
            {
               if (!f[k])
               {
                  ans-=e[j][4];
                  f[k]=true;
               }
               int s=k;
               k=next[k];
               next[s]=next[e[j][3]];
            }
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
