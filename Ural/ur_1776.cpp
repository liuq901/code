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
double f[410][410],s[410][410];
int main()
{
   int n;
   scanf("%d",&n);
   n-=2;
   f[0][0]=s[0][0]=1;
   for (int i=1;i<=n;i++)
      s[0][i]=1;
   for (int i=1;i<=n;i++)
   {
      for (int j=1;j<=i;j++)
      {
         int left=j-1,right=i-j,t=max(left,right);
         for (int k=1;k<=t+1;k++)
         {
            double tmp=0;
            tmp+=f[left][k-1]*s[right][k-1]+s[left][k-1]*f[right][k-1];
            tmp-=f[left][k-1]*f[right][k-1];
            f[i][k]+=tmp*(1.0/i);
         }
      }
      s[i][0]=0;
      for (int j=1;j<=n;j++)
         s[i][j]=s[i][j-1]+f[i][j];
   }
   double ans=0;
   for (int i=1;i<=n;i++)
      ans+=f[n][i]*i;
   printf("%.10lf\n",ans*10);
   system("pause");
   return(0);
}
