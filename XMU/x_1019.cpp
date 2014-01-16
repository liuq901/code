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
int b[2010],a[4000100][2];
vector <pair <int,int> > ans[2010];
int X[2010],Y[2010];
int main()
{
   int topsort(int);
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%d%d",&X[i],&Y[i]);
   int tot=0;
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
      {
         if (i==j)
            continue;
         if (X[i]>=X[j] && Y[i]>=Y[j])
            a[++tot][0]=j,a[tot][1]=b[i],b[i]=tot;
      }
   int limit=topsort(n);
   for (int i=1;i<=limit;i++)
   {
      sort(ans[i].begin(),ans[i].end());
      int l=ans[i].size();
      for (int j=0;j<l-1;j++)
         printf("%d %d ",ans[i][j].second,ans[i][j].first);
      printf("%d %d\n",ans[i][l-1].second,ans[i][l-1].first);
   }
   system("pause");
   return(0);
}
int topsort(int n)
{
   int d[2010]={0},q[2010][2];
   for (int i=1;i<=n;i++)
      for (int j=b[i];j;j=a[j][1])
      {
         int x=a[j][0];
         d[x]++;
      }
   int l=1,r=0;
   for (int i=1;i<=n;i++)
      if (!d[i])
         q[++r][0]=i,q[r][1]=1;
   while (l<=r)
   {
      int x=q[l][0],t=q[l][1];
      for (int i=b[x];i;i=a[i][1])
      {
         int y=a[i][0];
         d[y]--;
         if (!d[y])
            q[++r][0]=y,q[r][1]=t+1;
      }
      ans[t].push_back(make_pair(Y[x],X[x]));
      l++;
   }
   return(q[n][1]);
}
