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
int f[60][10];
int main()
{
   f[0][0]=1;
   for (int i=0;i<=50;i++)
      for (int j=1;j<=4;j++)
         for (int k=0;k<10;k++)
         {
            if (k>i)
               break;
            f[i][j]+=f[i-k][j-1];
         }
   int n;
   while (scanf("%d",&n)!=EOF)
      printf("%d\n",f[n][4]);
   system("pause");
   return(0);
}
