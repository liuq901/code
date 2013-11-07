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
const int a[]={1,5,10,25,50};
int ans[260];
int main()
{
   void init();
   init();
   int n;
   while (scanf("%d",&n)!=EOF)
      printf("%d\n",ans[n]);
   system("pause");
   return(0);
}
int f[260][110][10];
void init()
{
   int m=5;
   f[0][0][0]=1;
   for (int i=1;i<=250;i++)
      for (int j=1;j<=100;j++)
         for (int k=0;k<m;k++)
         {
            if (i<a[k])
               continue;
            for (int l=0;l<=k;l++)
               f[i][j][k]+=f[i-a[k]][j-1][l];
            ans[i]+=f[i][j][k];
         }
   ans[0]=1;
}
