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
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
int main()
{
   string check(string);
   string n,m;
   while (cin>>n>>m)
      printf("%s\n",check(n)==check(m)?"YES":"NO");
   system("pause");
   return(0);
}
string check(string s)
{
   string ans="";
   int l=s.size(),k=0;
   bool flag=false;
   if (s[0]=='-')
   {
      ans="-";
      k=1;
   }
   int t=-1;
   for (int i=k;i<l;i++)
   {
      if (s[i]=='.')
      {
         t=i;
         break;
      }
      if (s[i]!='0')
         flag=true;
      if (flag)
         ans+=s[i];
   }
   if (ans=="" || ans=="-")
      ans="0";
   if (t!=-1)
   {
      k=l;
      for (int i=l-1;i>t;i--)
         if (s[i]!='0')
         {
            k=i;
            break;
         }
      if (k!=l)
      {
         ans+=".";
         for (int i=t+1;t<=k;t++)
            ans+=s[i];
      }
   }
   return(ans);
}
