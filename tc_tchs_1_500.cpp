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
struct SymbolFrequency
{
   double language(vector <string> fre,vector <string> text)
   {
      int n=text.size();
      for (int i=0;i<n;i++)
      {
         string s=text[i];
         int l=s.size();
         for (int j=0;j<l;j++)
            if (isalpha(s[j]))
               a+=s[j];
      }
      double ans=1e100;
      n=fre.size();
      for (int i=0;i<n;i++)
         ans=min(ans,count(fre[i]));
      return(ans);
   }
private:
   string a;
   double count(string s)
   {
      double p[26]={0};
      stringstream sin(s);
      int tot=0;
      while (1)
      {
         char ch;
         int x;
         sin>>ch>>x;
         p[ch-'a']=x/100.0;
         tot+=x;
         if (tot==100)
            break;
      }
      double ans=0;
      int n=a.size(),sum[26]={0};
      for (int i=0;i<n;i++)
         sum[a[i]-'a']++;
      for (int i=0;i<26;i++)
         ans+=SQR(fabs(sum[i]-p[i]*n));
      return(ans);
   }
};
int main()
{
   int n,m;
   vector <string> a,b;
   scanf("%d%*c",&n);
   a.resize(n);
   for (int i=0;i<n;i++)
      getline(cin,a[i]);
   scanf("%d%*c",&m);
   b.resize(m);
   for (int i=0;i<m;i++)
      getline(cin,b[i]);
   SymbolFrequency p;
   printf("%lf\n",p.language(a,b));
   system("pause");
   return(0);
}
