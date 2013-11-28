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
struct Lottery
{
   vector <string> sortByOdds(vector <string> rules)
   {
      int n=rules.size();
      pair <ll,string> a[n];
      for (int i=0;i<n;i++)
      {
         int pos=rules[i].find(':');
         string name=rules[i].substr(0,pos);
         rules[i].erase(0,pos+2);
         int n,k;
         char sort,unique;
         stringstream sin(rules[i]);
         sin>>n>>k>>sort>>unique;
         a[i]=make_pair(calc(n,k,sort=='T',unique=='T'),name);
      }
      sort(a,a+n);
      vector <string> ans;
      ans.resize(n);
      for (int i=0;i<n;i++)
         ans[i]=a[i].second;
      return(ans);
   }
private:
   ll calc(int n,int k,bool sort,bool unique)
   {
      if (unique && sort)
         return(C(n,k));
      if (unique && !sort)
         return(P(n,k));
      if (!unique && !sort)
         return(Pow(n,k));
      if (!unique && sort)
         return(DP(n,k));
   }
   ll C(int n,int k)
   {
      ll ans=1;
      for (int i=1;i<=k;i++)
         ans=ans*(n-i+1)/i;
      return(ans);
   }
   ll P(int n,int k)
   {
      ll ans=1;
      for (int i=1;i<=k;i++)
         ans=ans*n--;
      return(ans);
   }
   ll Pow(int n,int k)
   {
      ll ans=1;
      for (int i=1;i<=k;i++)
         ans*=n;
      return(ans);
   }
   ll DP(int n,int m)
   {
      ll f[m+1][n+1];
      for (int i=1;i<=n;i++)
         f[1][i]=1;
      for (int i=2;i<=m;i++)
         for (int j=1;j<=n;j++)
         {
            f[i][j]=0;
            for (int k=1;k<=j;k++)
               f[i][j]+=f[i-1][k];
         }
      ll ans=0;
      for (int i=1;i<=n;i++)
         ans+=f[m][i];
      return(ans);
   }
};
int main()
{
   int n;
   scanf("%d%*c",&n);
   vector <string> p;
   for (int i=1;i<=n;i++)
   {
      string s;
      getline(cin,s);
      p.push_back(s);
   }
   Lottery t;
   p=t.sortByOdds(p);
   for (int i=0;i<n;i++)
      printf("%s\n",p[i].c_str());
   system("pause");
   return(0);
}
