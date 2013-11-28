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
bool a[10][10][10][10];
int n,num[100],ans[10][10],d[10][10],q[100][2];
int main()
{
   void topsort();
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      int t=n+1>>1;
      for (int j=t-1;j;j--)
      {
         a[i][j+1][i][j]=a[j+1][i][j][i]=true;
         d[i][j]++,d[j][i]++;
      }
      for (int j=t+1;j<=n;j++)
      {
         a[i][j-1][i][j]=a[j-1][i][j][i]=true;
         d[i][j]++,d[j][i]++;
      }
   }
   topsort();
   for (int i=1;i<=SQR(n);i++)
      scanf("%d",&num[i]);
   sort(num+1,num+SQR(n)+1);
   for (int i=1;i<=SQR(n);i++)
      ans[q[i][0]][q[i][1]]=num[SQR(n)-i+1];
   for (int i=1;i<=n;i++)
   {
      for (int j=1;j<n;j++)
         printf("%d ",ans[i][j]);
      printf("%d\n",ans[i][n]);
   }
   system("pause");
   return(0);
}
void topsort()
{
   int l,r;
   l=1,r=0;
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
         if (!d[i][j])
            q[++r][0]=i,q[r][1]=j;
   while (l<=r)
   {
      int x=q[l][0],y=q[l][1];
      for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
            if (a[x][y][i][j])
               if (!--d[i][j])
                  q[++r][0]=i,q[r][1]=j;
      l++;
   }
}
