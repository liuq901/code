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
struct PalindromeMaker
{
   string make(string base)
   {
      int n=base.size(),count[26]={0};
      for (int i=0;i<n;i++)
         count[base[i]-'A']++;
      int sum=0;
      for (int i=0;i<26;i++)
         sum+=count[i]&1;
      if (sum>=2)
         return("");
      string ans;
      char ch='a';
      for (int i=0;i<26;i++)
      {
         if (count[i]&1)
            ch=i+'A';
         int time=count[i]>>1;
         for (int j=1;j<=time;j++)
            ans+=i+'A';
         count[i]-=time;
      }
      if (isupper(ch))
      {
         ans+=ch;
         count[ch-'A']--;
      }
      for (int i=25;i>=0;i--)
      {
         int time=count[i];
         for (int j=1;j<=time;j++)
            ans+=i+'A';
      }
      return(ans);
   }
};
int main()
{
   string s;
   cin>>s;
   PalindromeMaker p;
   printf("%s\n",p.make(s).c_str());
   system("pause");
   return(0);
}
