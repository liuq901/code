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
#include <string>
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
const string month[]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
const string day[]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
map <string,int> num;
int main()
{
   for (int i=0;i<19;i++)
      num[month[i]]=i;
   int T;
   scanf("%d",&T);
   printf("%d\n",T);
   while (T--)
   {
      string s;
      int d,y;
      cin>>d>>s>>s>>y;
      int tot=y*365+num[s]*20+d;
      int ans_d,ans_m,ans_y;
      ans_y=tot/260;
      tot%=260;
      ans_d=tot%13,ans_m=tot%20;
      printf("%d %s %d\n",ans_d+1,day[ans_m].c_str(),ans_y);
   }
   system("pause");
   return(0);
}
