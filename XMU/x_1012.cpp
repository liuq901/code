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
const double pi=acos(-1.0);
const double eps=1e-7;
const int mod=11881376;
const int inf=1061109567;
int main()
{
   char ch;
   int i=0;
   while (scanf("%c",&ch)!=EOF)
   {
      if (isupper(ch))
         ch=(ch-'A'+mod-i)%26+'A';
      else if (islower(ch))
         ch=(ch-'a'+mod-i)%26+'a';
      printf("%c",ch);
      i++;
   }
   system("pause");
   return(0);
}
