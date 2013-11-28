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
int m,f[101],c[101],e[10001][3];
int main()
{
   void sort(int,int);
   int find(int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n;
      scanf("%d",&n);
      m=0;
      for (int i=1;i<=n;i++)
      {
         int x,y,z;
         scanf("%d%d%d",&x,&y,&z);
         c[x]=y;
         for (int i=1;i<=z;i++)
         {
            int p;
            scanf("%d",&p);
            if (x<p)
               e[++m][0]=x,e[m][1]=p;
         }
      }
      int ans=0;
      for (int i=1;i<=m;i++)
      {
         e[i][2]=c[e[i][0]]+c[e[i][1]];
         ans+=e[i][2];
      }
      for (int i=0;i<n;i++)
         f[i]=i;
      sort(1,m);
      int sum=0;
      for (int i=1;i<=m;i++)
      {
         int x=find(e[i][0]),y=find(e[i][1]);
         if (x==y)
            continue;
         ans-=e[i][2];
         sum++;
         if (sum==n-1)
            break;
         f[x]=y;
      }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
void sort(int l,int r)
{
   int i,j,x;
   i=l,j=r;
   x=e[l+r>>1][2];
   while (i<=j)
   {
      while (e[i][2]>x)
         i++;
      while (e[j][2]<x)
         j--;
      if (i<=j)
      {
         swap(e[i][0],e[j][0]);
         swap(e[i][1],e[j][1]);
         swap(e[i][2],e[j][2]);
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
int find(int x)
{
   if (x!=f[x])
      f[x]=find(f[x]);
   return(f[x]);
}
