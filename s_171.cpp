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
struct state
{
   int num,value,pos;
};
struct stu
{
   int ability,value,pos;
};
bool operator <(state a,state b)
{
   return(a.value>b.value);
}
bool operator <(stu a,stu b)
{
   return(a.value>b.value);
}
state a[110];
stu b[16010];
int ans[16010];
int main()
{
   int m,n=0;
   scanf("%d",&m);
   for (int i=1;i<=m;i++)
   {
      scanf("%d",&a[i].num);
      n+=a[i].num;
      a[i].pos=i;
   }
   for (int i=1;i<=m;i++)
      scanf("%d",&a[i].value);
   for (int i=1;i<=n;i++)
      scanf("%d",&b[i].ability);
   for (int i=1;i<=n;i++)
   {
      scanf("%d",&b[i].value);
      b[i].pos=i;
   }
   sort(a+1,a+m+1);
   sort(b+1,b+n+1);
   int best=1;
   for (int i=1;i<=n;i++)
   {
      bool flag=false;
      for (int j=1;j<=m;j++)
         if (a[j].num && b[i].ability>a[j].value)
         {
            a[j].num--;
            ans[b[i].pos]=a[j].pos;
            flag=true;
            break;
         }
      if (!flag)
      {
         while (!a[best].num)
            best++;
         ans[b[i].pos]=a[best].pos;
         a[best].num--;
      }
   }
   for (int i=1;i<=n;i++)
      printf("%d%c",ans[i],i==n?'\n':' ');
   system("pause");
   return(0);
}
