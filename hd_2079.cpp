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
int n,a[50];
int main()
{
   void work(int,int);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int k;
      scanf("%d%d",&n,&k);
      memset(a,0,sizeof(a));
      a[0]=1;
      while (k--)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         work(x,y);
      }
      printf("%d\n",a[n]);
   }
   system("pause");
   return(0);
}
int b[50];
void work(int x,int y)
{
   memcpy(b,a,sizeof(a));
   for (int i=1;i<=y;i++)
      for (int j=0;i*x+j<=n;j++)
         b[i*x+j]+=a[j];
   memcpy(a,b,sizeof(b));
}
