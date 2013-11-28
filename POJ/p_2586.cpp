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
int s,d,ans,a[13];
int main()
{
   void search(int);
   while (scanf("%d%d",&s,&d)!=EOF)
   {
      ans=-inf;
      search(1);
      if (ans<0)
         printf("Deficit\n");
      else
         printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
void search(int dep)
{
   if (dep==13)
   {
      for (int i=1;i<=8;i++)
      {
         int sum=0;
         for (int j=1;j<=5;j++)
            sum+=a[i+j-1];
         if (sum>=0)
            return;
      }
      int sum=0;
      for (int i=1;i<=12;i++)
         sum+=a[i];
      ans=max(ans,sum);
      return;
   }
   a[dep]=s;
   search(dep+1);
   a[dep]=-d;
   search(dep+1);
}
