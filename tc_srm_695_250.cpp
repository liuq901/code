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
struct BunnyComputer
{
   int getMaximum(vector <int> a,int k)
   {
      int n=a.size();
      k++;
      memset(f,0,sizeof(f));
      for (int i=0;i<n;i++)
         if (i-k>=0)
         {
            f[i][0]=max(f[i-k][0],f[i-k][1]);
            f[i][1]=f[i-k][0]+a[i-k]+a[i];
         }
      int ans=0;
      for (int i=1;i<=k;i++)
      {
         if (n-i<0)
            break;
         ans+=max(f[n-i][0],f[n-i][1]);
      }
      return(ans);
   }
private:
   int f[60][2];
};
int main()
{
   vector <int> a;
   int n;
   scanf("%d",&n);
   a.resize(n);
   for (int i=0;i<n;i++)
      scanf("%d",&a[i]);
   BunnyComputer p;
   int k;
   scanf("%d",&k);
   printf("%d\n",p.getMaximum(a,k));
   system("pause");
   return(0);
}
