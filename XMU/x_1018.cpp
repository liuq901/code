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
const double eps=1e-7;
const double pi=acos(-1.0);
int mod,a[2][2],one[2][2]={{0,1},{1,1}};
int main()
{
   void work(int n);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n;
      scanf("%d%d",&n,&mod);
      if (!n)
         printf("0\n");
      else
      {
         work(n);
         printf("%d\n",a[1][0]);
      }
   }
   system("pause");
   return(0);
}
void work(int x)
{
   void multi(int (*)[2],int (*)[2]);
   if (x==1)
   {
      memcpy(a,one,sizeof(one));
      return;
   }
   work(x>>1);
   multi(a,a);
   if (x&1)
      multi(a,one);
}
void multi(int (*a)[2],int (*b)[2])
{
   int c[2][2]={0};
   for (int i=0;i<2;i++)
      for (int j=0;j<2;j++)
         for (int k=0;k<2;k++)
            c[i][j]=(c[i][j]+a[i][k]*b[k][j])%mod;
   memcpy(a,c,sizeof(c));
}
