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
struct data
{
   int x,y,pos;
};
bool operator <(data a,data b)
{
   return(a.x<b.x || a.x==b.x && a.y>b.y);
}
data a[100010];
int f[100010],c[100010],b[100010],pre[100010];
bool flag[100010];
int main()
{
   int find(int,int);
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      scanf("%d%d",&a[i].x,&a[i].y);
      a[i].pos=i;
   }
   sort(a+1,a+n+1);
   int ans=0,k;
   for (int i=1;i<=n;i++)
   {
      int t=find(ans,a[i].y);
      pre[i]=b[t];
      if (t==ans)
      {
         c[t+1]=a[i].y;
         b[t+1]=k=i;
         ans++;
      }
      else if (a[i].y<c[t+1])
      {
         c[t+1]=a[i].y;
         b[t+1]=i;
      }
   }
   printf("%d\n",ans);
   for (int i=k;i;i=pre[i])
      f[a[i].pos]=true;
   k=0;
   for (int i=1;i<=n;i++)
   {
      if (!f[i])
         continue;
      printf("%d",i);
      if (++k==ans)
      {
         printf("\n");
         break;
      }
      printf(" ");
   }
   system("pause");
   return(0);
}
int find(int r,int value)
{
   int l=0,ans;
   while (l<=r)
   {
      int mid=l+r>>1;
      if (c[mid]<value)
         l=mid+1,ans=mid;
      else
         r=mid-1;
   }
   return(ans);
}
