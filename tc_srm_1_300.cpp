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
struct BinaryCode
{
   int p[51],q[51];
   vector <string> decode(string s)
   {
      vector <string> ans;
      ans.resize(2);
      int n=s.size();
      if (n==1)
      {
         if (s=="0")
            ans[0]="0",ans[1]="NONE";
         else if (s=="1")
            ans[0]="NONE",ans[1]="1";
         else
            ans[0]=ans[1]="NONE";
         return(ans);
      }
      for (int i=0;i<n;i++)
         q[i]=s[i]-'0';
      p[0]=0,p[1]=q[0]-p[0];
      for (int i=2;i<n;i++)
         p[i]=q[i-1]-p[i-1]-p[i-2];
      for (int i=0;i<n;i++)
      {
         if (p[i]<0 || p[i]>1)
         {
            ans[0]="NONE";
            break;
         }
         ans[0]+=p[i]+'0';
      }
      if (p[n-2]+p[n-1]!=q[n-1])
         ans[0]="NONE";
      p[0]=1,p[1]=q[0]-p[0];
      for (int i=2;i<n;i++)
         p[i]=q[i-1]-p[i-1]-p[i-2];
      for (int i=0;i<n;i++)
      {
         if (p[i]<0 || p[i]>1)
         {
            ans[1]="NONE";
            break;
         }
         ans[1]+=p[i]+'0';
      }
      if (p[n-2]+p[n-1]!=q[n-1])
         ans[1]="NONE";
      return(ans);
   }
};
int main()
{
   string s;
   cin>>s;
   BinaryCode p;
   printf("%s\n%s\n",p.decode(s)[0].c_str(),p.decode(s)[1].c_str());
   system("pause");
   return(0);
}
