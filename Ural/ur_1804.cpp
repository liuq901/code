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
int main()
{
   int check(int,int,int,int);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      string s,t;
      int x,y;
      cin>>t>>t>>t>>s>>t>>t>>x>>t>>t>>t>>y>>t;
      int ans1,ans2;
      if (s=="home")
      {
         for (int i=0;i<=30;i++)
            if (check(x,y,i,0)>=0)
            {
               ans1=i;
               break;
            }
         for (int i=30;i>=0;i--)
            if (check(x,y,i,30)<=0)
            {
               ans2=i;
               break;
            }
      }
      else
      {
         for (int i=0;i<=30;i++)
            if (check(i,0,x,y)>=0)
            {
               ans1=i;
               break;
            }
         for (int i=30;i>=0;i--)
            if (check(i,30,x,y)<=0)
            {
               ans2=i;
               break;
            }
      }
      printf("%d %d\n",ans1,ans2);
   }
   system("pause");
   return(0);
}
int check(int x1,int y1,int x2,int y2)
{
   if (x1+x2>y1+y2)
      return(1);
   if (x1+x2<y1+y2)
      return(-1);
   if (x2>y1)
      return(1);
   if (x2<y1)
      return(-1);
   return(0);
}
