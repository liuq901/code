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
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int x1,y1,x2,y2;
      scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
      if (x1+y1>x2+y2)
         swap(x1,x2),swap(y1,y2);
      int x=x1+y1,y=x2+y2;
      if (x==y)
         printf("%.3f\n",sqrt(SQR(x2-x1)+SQR(y2-y1)));
      else
      {
         double ans=sqrt(2)*(x+x2-x1+y*(y-1)/2.0-x*(x+1)/2.0);
         for (int i=x;i<y;i++)
            ans+=sqrt(2*SQR(i)+2*i+1);
         printf("%.3f\n",ans);
      }
   }
   system("pause");
   return(0);
}
