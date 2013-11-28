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
const double eps=1e-7;
const double pi=acos(-1.0);
map <string,int> p;
bool poli[110];
double x[110],y[110],d[110];
int a[110],hei[110],pp[110],rank[110];
int main()
{
   double dist(double,double,double,double);
   int calc(int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n;
      scanf("%d",&n);
      p.clear();
      int q_sum=0;
      for (int i=1;i<=n;i++)
      {
         string s;
         cin>>s;
         p.insert(make_pair(s,i));
         char ch;
         cin>>ch;
         poli[i]=ch=='p';
         q_sum+=!poli[i];
         scanf("%lf%lf%d",&x[i],&y[i],&rank[i]);
      }
      int m,order;
      scanf("%d",&m);
      string s;
      cin>>s;
      order=p[s];
      int tot=0;
      int ans,sum=0;
      int P=0;
      for (int i=1;i<=n;i++)
      {
         if (!poli[i] || i==order)
            continue;
         for (int j=1;j<=n;j++)
            d[j]=dist(x[i],y[i],x[j],y[j]);
         d[0]=dist(x[i],y[i],x[order],y[order]);
         sort(d+1,d+n+1);
         int k=0;
         for (int j=1;j<=n;j++)
            if (fabs(d[j]-d[0])<eps)
            {
               k=j;
               break;
            }
         k--;
         if (k!=1)
         {
            a[++P]=k;
            tot+=k-1;
         }
         if (k<=m)
            sum+=m-k+1; 
      }
      int t=0;
      for (int i=1;i<=n;i++)
      {
         if (poli[i] || i==order)
            continue;
         int k=rank[order];
         if (rank[i]<rank[order])
            k--;
         if (k<=m)
         {
            hei[++t]=m-k+1;
         }
      }
      for (int i=1;i<=t;i++)
         sum+=hei[i];
      ans=sum;
      int num=tot;
      sort(a+1,a+P+1);
      for (int i=1;i<=min(tot,n-1);i++)
      {
         for (int j=1;j<=P;j++)
            if (a[j]>1)
            {
               a[j]--;
               if (a[j]<=m)
                  sum++;
               break;
            }
         rank[order]--;
         for (int j=1;j<=t;j++)
         {
            if (hei[j]>1 || hei[j]==1 && m!=n-1)
               sum--,hei[j]--;
         }
         ans=max(ans,sum);
      }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
double dist(double x1,double y1,double x2,double y2)
{
   return(sqrt(SQR(x1-x2)+SQR(y1-y2)));
}
