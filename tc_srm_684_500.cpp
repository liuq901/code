#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
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
typedef complex <double> cp;
const double eps=1e-7;
const double pi=acos(-1);
struct ChickenOracle
{
   string theTruth(int n,int egg,int lie,int liar)
   {
      int a,b,c,d;
      bool Egg,Chicken;
      int t=egg+lie+liar-n;
      if (t&1)
         Egg=false;
      else
      {
         d=t>>1;
         c=lie-d;
         b=liar-d;
         a=egg-d;
         Egg=check(a,n) && check(b,n) && check(c,n) && check(d,n);
      }
      t=egg+lie+liar;
      if (t&1)
         Chicken=false;
      else
      {
         int p=t>>1;
         a=p-liar;
         b=p-egg;
         d=p-lie;
         c=n-a-b-d;
         Chicken=check(a,n) && check(b,n) && check(c,n) && check(d,n);
      }
      if (Egg && Chicken)
         return("Ambiguous");
      if (!Egg && Chicken)
         return("The chicken");
      if (Egg && !Chicken)
         return("The egg");
      return("The oracle is a lie");
   }
   bool check(int x,int n)
   {
      return(x>=0 && x<=n);
   }
};
int main()
{
   int a,b,c,d;
   scanf("%d%d%d%d",&a,&b,&c,&d);
   ChickenOracle p;
   printf("%s\n",p.theTruth(a,b,c,d).c_str());
   system("pause");
   return(0);
}
