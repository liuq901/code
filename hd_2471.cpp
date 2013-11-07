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
int q[4100000][2];
int a[2010][26],b[2010][26],A[2010],B[2010];
bool vis[2010][2010];
int main()
{
   int id=0;
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      int n1,n2;
      scanf("%d",&n1);
      for (int i=0;i<n1;i++)
      {
         scanf("%d",&A[i]);
         for (int j=0;j<n;j++)
         {
            int x;
            scanf("%d",&x);
            if (x==-1)
               a[i][j]=n1;
            else
               a[i][j]=x;
         }
      }
      scanf("%d",&n2);
      for (int i=0;i<n2;i++)
      {
         scanf("%d",&B[i]);
         for (int j=0;j<n;j++)
         {
            int x;
            scanf("%d",&x);
            if (x==-1)
               b[i][j]=n2;
            else
               b[i][j]=x;
         }
      }
      for (int i=0;i<n;i++)
         a[n1][i]=n1,b[n2][i]=n2;
      A[n1]=B[n2]=0;
      int l,r;
      bool flag=true;
      memset(vis,0,sizeof(vis));
      l=r=1,q[1][0]=0,q[1][1]=0;
      vis[0][0]=true;
      if (A[0]!=B[0])
      {
         flag=false;
         r=0;
      }
      while (l<=r)
      {
         int x0=q[l][0],y0=q[l][1];
         for (int i=0;i<n;i++)
         {
            int x=a[x0][i],y=b[y0][i];
            if (vis[x][y])
               continue;
            if (A[x]!=B[y])
            {
               flag=false;
               break;
            }
            vis[x][y]=true;
            q[++r][0]=x,q[r][1]=y;
         }
         if (!flag)
            break;
         l++;
      }
      printf("Case #%d: %s\n",++id,flag?"Yes":"No");
   }
   system("pause");
   return(0);
}
