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
#define MAXN 55
#define MAXM 1010
#define TIME 5000
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const double eps=1e-7;
const double pi=acos(-1.0);
double a[MAXN][MAXN];
int main()
{
   double dist(int,int,int,int,int,int);
   ios::sync_with_stdio(false);
   int n;
   while (cin>>n)
   {
      int x[MAXN],y[MAXN],z[MAXN];
      for (int i=1;i<=n;i++)
         cin>>x[i]>>y[i]>>z[i];
      for (int i=1;i<=n;i++)
      {
         for (int j=1;j<=n;j++)
            a[i][j]=dist(x[i],y[i],z[i],x[j],y[j],z[j]);
         a[i][n+1]=0;
      }
      double ans=1e100;
      for (int time=1;time<=TIME;time++)
      {
         int pos[MAXN];
         for (int i=1;i<=n;i++)
            pos[i]=i;
         for (int i=2;i<=n;i++)
         {
            int x=1;
            while (x==1)
               x=rand()%n+1;
            swap(pos[i],pos[x]);
         }
         pos[n+1]=n+1;
         double now=0;
         for (int i=2;i<=n;i++)
         {
            int x=pos[i-1],y=pos[i];
            now+=a[x][y];
         }
         bool flag=true;
         while (flag)
         {
            flag=false;
            for (int i=2;i<=n;i++)
            {
               for (int j=i+1;j<=n;j++)
               {
                  int x=pos[i],y=pos[j];
                  double tmp=now-a[pos[i-1]][x]-a[y][pos[j+1]]+a[pos[i-1]][y]+a[x][pos[j+1]];
                  if (tmp<now)
                  {
                     now=tmp;
                     int t=j;
                     for (int k=i;k<=i+j>>1;k++)
                        swap(pos[k],pos[t--]);
                     flag=true;
                  }
               }
            }
         }
         ans=min(ans,now);
      }
      cout<<setprecision(1)<<fixed<<ans<<endl;
   }
   system("pause");
   return(0);
}
double dist(int x1,int y1,int z1,int x2,int y2,int z2)
{
   return(sqrt(double(SQR(x1-x2)+SQR(y1-y2)+SQR(z1-z2))));
}
