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
stack <int> s;
int a[1010];
int main()
{
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      while (1)
      {
         scanf("%d",&a[1]);
         if (!a[1])
            break;
         for (int i=2;i<=n;i++)
            scanf("%d",&a[i]);
         int p=1;
         for (int i=1;i<=n;i++)
         {
            while ((s.empty() || s.top()!=a[i]) && p<=n)
               s.push(p++);
            if (s.top()==a[i])
               s.pop();
            else
               break;
         }
         printf("%s\n",s.empty()?"Yes":"No");
         while (!s.empty())
            s.pop();
      }
      printf("\n");
   }
   system("pause");
   return(0);
}
