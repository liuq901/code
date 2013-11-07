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
int main()
{
   int calc(int);
   ios::sync_with_stdio(false);
   int m,n,ans[MAXN];
   while (cin>>m>>n)
   {
      ans[0]=0;
      for (int i=m;i<=n;i++)
      {
         int a,b,c;
         a=i/100,b=i/10%10,c=i%10;
         if (calc(a)+calc(b)+calc(c)==i)
            ans[++ans[0]]=i;
      }
      if (!ans[0])
         cout<<"no"<<endl;
      else
      {
         for (int i=1;i<ans[0];i++)
            cout<<ans[i]<<" ";
         cout<<ans[ans[0]]<<endl;
      }
   }
   system("pause");
   return(0);
}
int calc(int x)
{
   return(SQR(x)*x);
}
