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
int a[110];
double f[110];
int main()
{
   int l;
   while (scanf("%d",&l)!=EOF)
   {
      int n,C,T,vx,vt1,vt2;
      scanf("%d%d%d%d%d%d",&n,&C,&T,&vx,&vt1,&vt2);
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      a[0]=0,a[++n]=l;
      for (int i=1;i<=n;i++)
         f[i]=1e100;
      f[0]=0;
      for (int i=1;i<=n;i++)
         for (int j=0;j<i;j++)
         {
            int s=a[i]-a[j];
            f[i]=min(f[i],f[j]+min(double(s)/vt2,(s<=C?double(s)/vt1:double(C)/vt1+double(s-C)/vt2)+(j?T:0)));
         }
      printf("%s\n",f[n]<double(l)/vx?"What a pity rabbit!":"Good job,rabbit!");
   }
   system("pause");
   return(0);
}
