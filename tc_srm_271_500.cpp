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
struct GridCut
{
   int cutLength(int width,int height,int n)
   {
      if (width>height)
         swap(width,height);
      n=min(n,width*height-n);
      if (!n)
         return(0);
      int ans;
      if (n%width)
         ans=width+1;
      else
         ans=width;
      for (int i=1;i<=width;i++)
         for (int j=1;j<=height;j++)
         {
            if (i*j>n)
               break;
            if (i*j==n)
               ans=min(ans,i+j);
            else
            {
               int t=n-i*j;
               if (t<=min(i,j))
                  ans=min(ans,i+j+1);
            }
         }
      return(ans);
   }
};
int main()
{
   int x,y,z;
   scanf("%d%d%d",&x,&y,&z);
   GridCut p;
   printf("%d\n",p.cutLength(x,y,z));
   system("pause");
   return(0);
}
