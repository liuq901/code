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
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
stack <int> a;
int c[260];
int main()
{
   char ch;
   c['(']=c[')']=0,c['<']=c['>']=1,c['{']=c['}']=2,c['[']=c[']']=3;
   bool flag=true;
   while (scanf("%c",&ch)!=EOF)
   {
      if (ch=='(' || ch=='<' || ch=='{' || ch=='[')
         a.push(c[ch]);
      if (ch==')' || ch=='>' || ch=='}' || ch==']')
      {
         if (a.empty() || a.top()!=c[ch])
         {
            flag=false;
            break;
         }
         a.pop();
      }
   }
   if (!a.empty())
      flag=false;
   printf("%s\n",!flag?"NO":"YES");
   system("pause");
   return(0);
}
