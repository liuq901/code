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
char a[100][100];
int main()
{
   void work(int,int,char,char);
   int n;
   char c1,c2;
   bool flag=true;
   while (cin>>n>>c1>>c2)
   {
      if (n+1>>1&1)
         swap(c1,c2);
      work(1,n,c2,c1);
      if (n!=1)
         a[1][1]=a[1][n]=a[n][1]=a[n][n]=' ';
      if (!flag)
         printf("\n");
      flag=false;
      for (int i=1;i<=n;i++)
      {
         for (int j=1;j<=n;j++)
            printf("%c",a[i][j]);
         printf("\n");
      }
   }
   system("pause");
   return(0);
}
void work(int x,int y,char now,char next)
{
   for (int i=x;i<=y;i++)
      a[x][i]=a[y][i]=a[i][x]=a[i][y]=now;
   if (x!=y)
      work(x+1,y-1,next,now);
}
