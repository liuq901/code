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
#define MAXN 28
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const double pi=acos(-1.0);
const double eps=1e-7;
const string now="aeiou";
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
      int l=s.size(),ans[MAXN]={0};
      for (int i=0;i<l;i++)
         if (isalpha(s[i]))
            ans[tolower(s[i])-'a']++;
      for (int i=0;i<5;i++)
         cout<<now[i]<<":"<<ans[now[i]-'a']<<endl;
      if (t)
         cout<<endl; 
   }
   system("pause");
   return(0);
}
