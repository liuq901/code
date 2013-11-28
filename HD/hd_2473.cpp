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
int f[1600001];
int main()
{
   int find(int);
   int id=0;
   while (1)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      if (!n && !m)
         break;
      for (int i=1;i<=n;i++)
         f[i]=i;
      int t=n;
      for (int i=1;i<=m;i++)
      {
         char ch;
         while (1)
         {
            scanf("%c",&ch);
            if (isalpha(ch))
               break;
         }
         if (ch=='M')
         {
            int x,y;
            scanf("%d%d",&x,&y);
            x++,y++;
            x=find(x),y=find(y);
            if (x<y)
               swap(x,y);
            if (x>n)
               f[y]=x;
            else
               t++,f[x]=t,f[y]=t,f[t]=t;
         }
         else
         {
            int x;
            scanf("%d",&x);
            x++;
            f[x]=x;
         }
      }
      for (int i=1;i<=n;i++)
         f[i]=find(f[i]);
      sort(f+1,f+n+1);
      int ans=0;
      f[0]=-1;
      for (int i=1;i<=n;i++)
         if (f[i]!=f[i-1])
            ans++;
      printf("Case #%d: %d\n",++id,ans);
   }
   system("pause");
   return(0);
}
int find(int x)
{
   if (x!=f[x])
      f[x]=find(f[x]);
   return(f[x]);
}
