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
int a[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
   bool leap(int);
   ios::sync_with_stdio(false);
   int year,month,day;
   char ch;
   while (cin>>year>>ch>>month>>ch>>day)
   {
      a[2]=leap(year)?29:28;
      int ans=0;
      for (int i=1;i<month;i++)
         ans+=a[i];
      cout<<ans+day<<endl;
   }
   system("pause");
   return(0);
}
bool leap(int x)
{
   return(!(x%400) || !(x%4) && x%100);
}
