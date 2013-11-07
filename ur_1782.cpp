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
string s;
int ans=0;
int main()
{
   void work();
   cin>>s;
   work();
   system("pause");
   return(0);
}
void work()
{
   bool check(int,int);
   void did(int,int);
   if (s.empty())
   {
      printf("%d\n",ans);
      return;
   }
   string S=s;
   int m=s.size()-1;
   if (!m)
   {
      ans++;
      s="";
      work();
      printf("front %c\n",S[0]);
      return;
   }
   for (int i=0;i<=2;i++)
      for (int j=0;j<=2;j++)
         if (check(i,m-j))
         {
            ans+=i+j;
            did(i,m-j);
            work();
            printf("double\n");
            for (int k=1;k<=i;k++)
            {
               int t=k-1;
               printf("front %c\n",S[t]);
            }
            for (int k=j;k;k--)
            {
               int t=m-k+1;
               printf("back %c\n",S[t]);
            }
            return;
         }
}
bool check(int l,int r)
{
   if (l>r)
      return(true);
   if (r-l+1&1)
      return(false);
   for (int i=l;i<=r;i+=2)
      if (s[i]==s[i+1])
         return(false);
   return(true);
}
string t;
void did(int l,int r)
{
   ans++;
   int k=0;
   t="";
   for (int i=l;i<=r;i+=2)
      t+=s[i];
   s=t;
}
