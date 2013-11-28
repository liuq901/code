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
struct CardStraights
{
   int longestStraight(vector <int> cards)
   {
      int n=cards.size(),k=0;
      for (int i=0;i<n;i++)
         if (!cards[i])
            k++;
         else
            flag.set(cards[i]);
      int ans=0;
      for (int i=1;i<=1000000;i++)
      {
         int len=0,time=0,t=i;
         while (1)
         {
            if (!flag[t])
               time++;
            if (time>k)
               break;
            len++,t++;
         }
         ans=max(ans,len);
      }  
      return(ans);
   }
public:
   static bitset <1000001> flag;
};
bitset <1000001> CardStraights::flag;
int main()
{
   int n;
   scanf("%d",&n);
   vector <int> a;
   a.resize(n);
   for (int i=0;i<n;i++)
      scanf("%d",&a[i]);
   CardStraights p;
   printf("%d\n",p.longestStraight(a));
   system("pause");
   return(0);
}
