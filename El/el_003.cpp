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
#define MAXN 210
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
bool a[MAXN][MAXN];
deque <int> p;
typedef deque <int>::iterator data;
int main()
{
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      for (int j=1;j<=i;j++)
      {
         char ch;
         cin>>ch;
         if (ch=='+')
            a[i][j]=true;
         else
            a[j][i]=true;
      }
   p.push_back(1);
   for (int i=2;i<=n;i++)
   {
      if (a[i][p[0]])
         p.push_front(i);
      else if (a[p[i-2]][i])
         p.push_back(i);
      else
         for (data k=p.begin();k!=p.end();k++)
            if (a[*k][i] && a[i][*(k+1)])
            {
               p.insert(k+1,i);
               break;
            }
   }
   printf("%d",p[0]);
   for (int i=1;i<n;i++)
      printf(" %d",p[i]);
   printf("\n");
   system("pause");
   return(0);
}
