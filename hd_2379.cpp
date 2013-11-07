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
#define MAXN 1010
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
string s;
int a[7800];
ll c[6][6],f[51][6];
int main()
{
   ll calc(int,int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int m,n,q;
      scanf("%d%d%d",&m,&n,&q);
      for (int i=1;i<=m;i++)
      {
         cin>>s;
         a[i]=s.size();
      }
      for (int i=1;i<=5;i++)
      {
         c[i][0]=c[i][i]=1;
         for (int j=1;j<i;j++)
            c[i][j]=c[i-1][j]+c[i-1][j-1];
      }
      memset(f,0,sizeof(f));
      f[0][0]=1;
      for (int i=1;i<=m;i++)
      {
         for (int j=50;j>=a[i];j--)
            for (int k=1;k<=n;k++)
               for (int p=1;p<=k;p++)
               {
                  if (j-p*a[i]<0)
                     break;
                  f[j][k]+=f[j-p*a[i]][k-p]*c[k][p];  
               }
      }
      while (q--)
      {
         int x;
         scanf("%d",&x);
         cout<<f[x][n]<<endl;
      }
   }
   system("pause");
   return(0);
}
