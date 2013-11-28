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
double a[410],b[410];
int n;
int main()
{
   void work(int,double);
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%lf",&a[i]);
   double t,min=1e100;
   int x;
   for (int i=1;i<n;i++)
      for (int j=i+1;j<=n;j++)
      {
         double d=(a[j]-a[i])/(j-i);
         work(i,d);
         double now=0;
         for (int k=1;k<=n;k++)
            now+=fabs(a[k]-b[k]);
         if (now<min)
            min=now,x=i,t=d;
      }
   printf("%.10f\n",min);
   work(x,t);
   for (int i=1;i<=n;i++)
      printf("%.10f%c",b[i],i==n?'\n':' ');
   system("pause");
   return(0);
}
void work(int x,double d)
{
   b[x]=a[x];
   for (int i=x-1;i;i--)
      b[i]=b[i+1]-d;
   for (int i=x+1;i<=n;i++)
      b[i]=b[i-1]+d;
}
