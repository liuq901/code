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
#define MAXN 1010
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
struct SimpleDuplicateRemover
{
   vector <int> process(vector <int> sequence)
   {
      set <int> a;
      vector <int> ans;
      int n=sequence.size();
      for (int i=n-1;i>=0;i--)
         if (!a.count(sequence[i]))
         {
            a.insert(sequence[i]);
            ans.push_back(sequence[i]);
         }
      int l=ans.size();
      for (int i=0;i<l/2;i++)
         swap(ans[i],ans[l-i-1]);
      return(ans);
   }
};
int main()
{
   int n;
   vector <int> a;
   scanf("%d",&n);
   a.resize(n);
   for (int i=0;i<n;i++)
      scanf("%d",&a[i]);
   SimpleDuplicateRemover p;
   a=p.process(a);
   n=a.size();
   for (int i=0;i<n;i++)
      printf("%d\n",a[i]);
   system("pause");
   return(0);
}
