#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
#include <cstdarg>
#include <iostream>
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
#define MAXN 1000010
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const double eps=1e-7;
const double pi=acos(-1.0);
int ans[MAXN][2];
int main()
{
   void init();
   init();
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      printf("%d %d\n",ans[n][0],ans[n][1]);
   }
   system("pause");
   return(0);
}
int a[MAXN];
void init()
{
   for (int i=1;i<=1000000;i++)
   {
      int x=i*(i+1)*(i+2)/6;
      if (x>1000000)
         break;
      a[++a[0]]=x;
   }
   memset(ans,63,sizeof(ans));
   ans[0][0]=ans[0][1]=0;
   for (int i=1;i<=1000000;i++)
      for (int j=1;j<=a[0];j++)
      {
         int x=a[j];
         if (i<x)
            break;
         ans[i][0]=min(ans[i][0],ans[i-x][0]+1);
         if (x&1)
            ans[i][1]=min(ans[i][1],ans[i-x][1]+1);
      }
}
