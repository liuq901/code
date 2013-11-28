#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cstdarg>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iomanip>
#define SQR(x) ((x)*(x))
#define MAXN 1010
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const double pi=acos(-1.0);
const double eps=1e-7;
int main()
{
   ios::sync_with_stdio(false);
   string s;
   while (cin>>s)
   {
      int l=s.size();
      char ch=0;
      for (int i=0;i<l;i++)
         ch=max(ch,s[i]);
      for (int i=0;i<l;i++)
      {
         cout<<s[i];
         if (ch==s[i])
            cout<<"(max)";
      }
      cout<<endl;
   }
   system("pause");
   return(0);
}
