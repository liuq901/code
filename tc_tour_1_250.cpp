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
int a[100001],b[100001];
struct HowEasy
{
   int pointVal(string s)
   {
      int now,t=0,l=s.size();
      bool flag=false;
      for (int i=0;i<l;i++)
      {
         if (s[i]==' ' && flag)
         {
            b[t]=now;
            now=-1;
            flag=false;
            continue;
         }
         if (!flag)
            a[++t]=i;
         flag=true;
         now=i;
      }
      if (now!=-1)
         b[t]=now;
      int ans=0,sum=0;
      for (int i=1;i<=t;i++)
      {
         int now=0;
         for (int j=a[i];j<=b[i];j++)
         {
            if (!isalpha(s[j]) && (j!=b[i] || s[j]!='.' || a[i]==b[i]))
            {
               now=-1;
               break;
            }
            now++;
            if (s[j]=='.')
               now--;
         }
         if (now!=-1)
            ans+=now,sum++;
      }
      if (sum)
         ans/=sum;
      if (ans<=3)
         return(250);
      else if (ans>=6)
         return(1000);
      else
         return(500);
   }
};
int main()
{
   string s;
   getline(cin,s);
   HowEasy p;
   printf("%d\n",p.pointVal(s));
   system("pause");
   return(0);
}
