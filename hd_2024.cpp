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
   int t;
   cin>>t;
   string s;
   getline(cin,s);
   while (t--)
   {
      getline(cin,s);
      bool flag;
      flag=isalpha(s[0]) || s[0]=='_';
      if (flag)
      {
         int n=s.size();
         for (int i=0;i<n;i++)
            if (!isalnum(s[i]) && s[i]!='_')
            {
               flag=false;
               break;
            }
      }
      cout<<(flag?"yes":"no")<<endl;
   }
   system("pause");
   return(0);
}
