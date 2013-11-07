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
char a[26][26],ans[410][410];
int n;
int main()
{
   void move(int,int);
   int k;
   scanf("%d%d",&n,&k);
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
         a[i][j]=(i-1)*n+j<=k?'*':'.';
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
         move(i,j);
   for (int i=1;i<=SQR(n);i++)
   {
      for (int j=1;j<=SQR(n);j++)
         printf("%c",ans[i][j]);
      printf("\n");
   }
   system("pause");
   return(0);
}
void move(int x,int y)
{
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
      {
         int p=i+y-1,q=j+x-1;
         if (p>n)
            p-=n;
         if (q>n)
            q-=n;
         ans[(x-1)*n+i][(y-1)*n+j]=a[p][q];
      }
}
