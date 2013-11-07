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
string s,t,ans;
int main()
{
   void work(int,int,int,int);
   while (cin>>s>>t)
   {
      int n=s.size();
      ans="";
      work(0,n-1,0,n-1);
      cout<<ans<<endl;
   }
   system("pause");
   return(0);
}
void work(int l1,int r1,int l2,int r2)
{
   if (l1>r1 || l2>r2)
      return;
   char root=s[l1];
   int k;
   for (int i=l2;i<=r2;i++)
      if (t[i]==root)
      {
         k=i;
         break;
      }
   work(l1+1,k-l2+l1,l2,k-1);
   work(k-l2+l1+1,r1,k+1,r2);
   ans+=root;
}
