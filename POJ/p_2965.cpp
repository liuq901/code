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
int main()
{
   bool a[5][5]={0};
   for (int i=1;i<=4;i++)
      for (int j=1;j<=4;j++)
      {
         char ch;
         cin>>ch;
         if (ch=='-')
            continue;
         for (int k=1;k<=4;k++)
            a[i][k]=!a[i][k],a[k][j]=!a[k][j];
         a[i][j]=!a[i][j];
      }
   int ans=0;
   for (int i=1;i<=4;i++)
      for (int j=1;j<=4;j++)
         ans+=a[i][j];
   printf("%d\n",ans);
   for (int i=1;i<=4;i++)
      for (int j=1;j<=4;j++)
         if (a[i][j])
            printf("%d %d\n",i,j);
   system("pause");
   return(0);
}
