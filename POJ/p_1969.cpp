#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
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
#define MAXN 3200
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=(1<<30)-1;
const double eps=1e-7;
const double pi=acos(-1);
int a[MAXN];
int main()
{
   ios::sync_with_stdio(false);
   for (int i=1;i<=3162;i++)
      a[i]=a[i-1]+i;
   int n;
   while (cin>>n)
   {
      int pos;
      for (int i=1;i<=3162;i++)
         if (a[i]>=n)
         {
            pos=i;
            break;
         }
      int x,y;
      x=pos&1?pos+a[pos-1]-n+1:n-a[pos-1];
      y=pos+1-x;
      cout<<"TERM "<<n<<" IS "<<x<<"/"<<y<<endl;
   }
   system("pause");
   return(0);
}
