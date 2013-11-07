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
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int pos[520]={0};
      bool f[520]={0};
      int n,m;
      scanf("%d%d",&n,&m);
      int p[10];
      for (int i=1;i<=m;i++)
         scanf("%d",&p[i]);
      p[0]=1;
      sort(p,p+m+1);
      int l1=0,l2=2,x=0;
      while (!l1)
      {
         f[l2]=true;
         for (int j=0;j<=m;j++)
         {
            if (l2-p[j]<=0 || !f[l2])
               break;
            f[l2]&=f[l2-p[j]];
         }
         f[l2]=!f[l2];
         if (pos[x])
            l1=pos[x];
         else if (l2>9)
            pos[x]=l2;
         x=x<<1&511|f[l2];
         l2++;
      }
      bool flag=n<l2?f[n]:f[(n-l1)%(l2-l1-1)+l1];
      printf("%s\n",flag?"FIRST PLAYER MUST WIN":"SECOND PLAYER MUST WIN");
   }
   system("pause");
   return(0);
}
