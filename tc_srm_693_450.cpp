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
struct QuickSort
{
   double getEval(vector <int> a)
   {
      if (hash.count(a))
         return(hash[a]);
      int n=a.size();
      if (n<=1)
         return(0);
      double ans=0;
      for (int i=0;i<n;i++)
      {
         vector <int> l,r;
         int sum=0;
         for (int j=0;j<n;j++)
         {
            if (a[j]<a[i])
            {
               l.push_back(a[j]);
               if (j>i)
                  sum++;
            }
            if (a[j]>a[i])
            {
               r.push_back(a[j]);
               if (j<i)
                  sum++;
            }
         }
         ans+=(sum+getEval(l)+getEval(r))/n;
      }
      hash[a]=ans;
      return(ans);
   }
private:
   map <vector <int>,double> hash;
};
int main()
{
   int n;
   vector <int> a;
   scanf("%d",&n);
   a.resize(n);
   for (int i=0;i<n;i++)
      scanf("%d",&a[i]);
   QuickSort p;
   printf("%.10f\n",p.getEval(a));
   system("pause");
   return(0);
}
