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
struct SequenceOfNumbers
{
   vector <string> rearrange(vector <string> a)
   {
      vector <int> b;
      int n=a.size();
      b.resize(n);
      for (int i=0;i<n;i++)
      {
         stringstream sin(a[i]);
         sin>>b[i];
      }
      sort(b.begin(),b.end());
      vector <string> ans;
      ans.resize(n);
      for (int i=0;i<n;i++)
      {
         stringstream sout;
         sout<<b[i];
         sout>>ans[i];
      }
      return(ans);
   }
};
int main()
{
   int n;
   scanf("%d",&n);
   vector <string> a;
   a.resize(n);
   for (int i=0;i<n;i++)
      cin>>a[i];
   SequenceOfNumbers p;
   a=p.rearrange(a);
   for (int i=0;i<n;i++)
      cout<<a[i]<<endl;
   system("pause");
   return(0);
}
