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
set <string> a;
char S[10010];
int main()
{
   while (1)
   {
      gets(S);
      if (S[0]=='#')
         break;
      a.clear();
      int l=strlen(S);
      string s;
      for (int i=0;i<l;i++)
         if (isalpha(S[i]))
            s+=S[i];
         else
         {
            if (s!="")
               a.insert(s);
            s="";
         }
      if (s!="")
         a.insert(s);
      printf("%d\n",a.size());
   }
   system("pause");
   return(0);
}
