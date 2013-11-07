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
int x[210],y[210];
ll p[210],q[210];
double dist[210];
int main()
{
   int n,m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=n;i++)
      scanf("%d%d",&x[i],&y[i]);
   if (m<=2)
      printf("0.00000000000\n");
   else
   {
      double ans=1e100;
      for (int i=1;i<n;i++)
      {
         for (int j=i+1;j<=n;j++)
         {
            ll a,b,c,x1,y1,x2,y2;
            x1=x[i],y1=y[i],x2=x[j],y2=y[j];
            a=y1-y2,b=x2-x1,c=x1*y2-x2*y1;
            int sum=0;
            p[0]=q[0]=0;
            for (int k=1;k<=n;k++)
            {
               ll now=a*x[k]+b*y[k]+c;
               if (!now)
                  sum++;
               else if (now>0)
                  p[++p[0]]=now;
               else
                  q[++q[0]]=-now;
            }
            if (sum>=m)
            {
               ans=0;
               break;
            }
            int limit=m-sum;
            if (p[0]>=limit)
            {
               for (int k=1;k<=p[0];k++)
                  dist[k]=p[k]/sqrt(double(SQR(a)+SQR(b)));
               sort(dist+1,dist+p[0]+1);
               ans=min(ans,dist[limit]);
            }
            if (q[0]>=limit)
            {
               for (int k=1;k<=q[0];k++)
                  dist[k]=q[k]/sqrt(double(SQR(a)+SQR(b)));
               sort(dist+1,dist+q[0]+1);
               ans=min(ans,dist[limit]);
            }
         }   
         if (fabs(ans)<1)
            break;
      }
      ans-=1;
      if (ans<0)
         ans=0;
      printf("%.10lf\n",ans);
   }
   system("pause");
   return(0);
}
