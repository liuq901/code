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
set <string> p;
map <string,pair <int,int> > a;
typedef map <string,pair <int,int> >::iterator data;
int main()
{
   int id=0;
   while (1)
   {
      int n,m,k;
      scanf("%d",&n);
      if (!n)
         break;
      scanf("%d%d",&m,&k);
      a.clear();
      for (int i=1;i<=n;i++)
      {
         p.clear();
         string s,t;
         cin>>s>>t;
         int l=s.size(),flag=t=="Yes";
         for (int j=0;j<=l-k;j++)
         {
            string now=s.substr(j,k);
            if (!p.count(now))
            {
               p.insert(now);
               a[now].first+=flag;
               a[now].second++;
            }
         }
      }
      string ans="No solution";
      int x=1,y=0;
      for (data k=a.begin();k!=a.end();k++)
      {
         int p=k->second.first,q=k->second.second;
         if (q>=m && (p*y<x*q || p*y==x*q && q>y))
            x=p,y=q,ans=k->first;
      }
      printf("Case %d: %s\n",++id,ans.c_str());
   }
   system("pause");
   return(0);
}
