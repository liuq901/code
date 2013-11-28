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
int X[31],Y[31],x[31],y[31];
int a[31];
int main()
{
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int p,q,n;
      scanf("%d%d%d",&p,&q,&n);
      int minx,miny,k;
      minx=miny=1<<30,k=-1;
      for (int i=1;i<=n;i++)
      {
         scanf("%d%d",&X[i],&Y[i]);
         if (X[i]<minx)
            minx=X[i],k=i;
         else if (X[i]==minx && Y[i]<miny)
            miny=Y[i],k=i;
      }
      int t=0;
      for (int i=k;i<=n;i++)   
         x[++t]=X[i],y[t]=Y[i];
      for (int i=1;i<k;i++)
         x[++t]=X[i],y[t]=Y[i];
      int m=2;
      a[1]=1,a[2]=2;
      for (int i=3;i<=n;i++)
      {
         int p,q,x1,y1,x2,y2;
         while (1)
         {
            p=a[m-1],q=a[m];
            x1=x[q]-x[p],y1=y[q]-y[p],x2=x[i]-x[q],y2=y[i]-y[q];
            if (m==1 || x1*y2-x2*y1<=0)
            {
               a[++m]=i;
               break;
            }
            m--;
         }
      }
      while (1)
      {
         int p=a[m-1],q=a[m];
         int x1=x[q]-x[p],y1=y[q]-y[p],x2=x[1]-x[q],y2=y[1]-y[q];
         if (m==2 || x1*y2-x2*y1<=0)
            break;
         m--;
      }
      int sum=0,ans=0;
      for (int i=1;i<m;i++)
         if (a[i]+1!=a[i+1])
            sum++;
         else
            ans++;
      if (a[m]!=n)
         sum++;
      else
         ans++;
      int tot=-sum*p+ans*q;
      if (tot<0)
         tot=0;
      printf("%d\n",tot);
   }
   system("pause");
   return(0);
}
