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
bool flag;
int main()
{
   int work();
   int n;
   while (scanf("%d",&n)!=EOF)
   {
      int s=0;
      flag=false;
      for (int i=1;i<=n;i++)
         s^=work();
      if (!flag)
         printf("%s\n",s?"QQ":"PP");
      else
         printf("%s\n",s?"PP":"QQ");
   }
   system("pause");
   return(0);
}
int b[110],a[10000][2];
int work()
{
   int count(int,int);
   int n;
   scanf("%d",&n);
   memset(b,0,sizeof(b));
   for (int i=1;i<n;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      a[i][0]=y,a[i][1]=b[x],b[x]=i;
      a[i+n][0]=x,a[i+n][1]=b[y],b[y]=i+n;
   }
   int t=count(1,0);
   if (t>1)
      flag=true;
   return(t);
}
int count(int x,int father)
{
   int s=0;
   for (int i=b[x];i;i=a[i][1])
   {
      int y=a[i][0];
      if (y==father)
         continue;
      s^=(count(y,x)+1);
   }
   return(s);
}
