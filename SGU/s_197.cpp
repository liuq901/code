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
const double eps=1e-7;
const double pi=acos(-1.0);
struct matrix
{
   static int mod,m;
   int a[32][32];
   matrix()
   {
      memset(a,0,sizeof(a));
   }
   int *operator [](int x)
   {
      return(a[x]);
   }
};
matrix operator *(matrix a,matrix b)
{
   matrix c;
   for (int i=0;i<c.m;i++)
      for (int j=0;j<c.m;j++)
         for (int k=0;k<c.m;k++)
            c[i][j]=(c[i][j]+a[i][k]*b[k][j])%c.mod;
   return(c);
}
matrix one,a;
string n;
int m,matrix::mod,matrix::m,b[110];
int main()
{
   bool check(int,int);
   void work();
   cin>>n>>m>>matrix::mod;
   matrix::m=1<<m;
   for (int i=0;i<1<<m;i++)
      for (int j=0;j<1<<m;j++)
         one[i][j]=check(i,j);
   b[0]=n.size();
   for (int i=1;i<=b[0];i++)
      b[i]=n[b[0]-i]-'0';
   if (b[0]==1 && b[1]==1)
      printf("%d\n",matrix::m%matrix::mod);
   else
   {
      b[1]--;
      for (int i=1;i<=b[0];i++)
      {
         if (b[i]>=0)
            break;
         b[i]+=10,b[i+1]--;
      }
      while (!b[b[0]])
         b[0]--;
      work();
      int ans=0;
      for (int i=0;i<1<<m;i++)
         for (int j=0;j<1<<m;j++)
            ans=(ans+a[i][j])%matrix::mod;
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
bool check(int x,int y)
{
   int a[10],b[10];
   for (int i=1;i<=m;i++)
   {
      a[i]=x&1,x>>=1;
      b[i]=y&1,y>>=1;
   }
   for (int i=1;i<m;i++)
      if (a[i]==a[i+1] && b[i]==b[i+1] && a[i]==b[i])
         return(false);
   return(true);
}
void work()
{
   bool div();
   if (b[0]==1 && b[1]==1)
   {
      a=one;
      return;
   }
   bool p=div();
   work();
   a=a*a;
   if (p)
      a=a*one;
}
bool div()
{
   int t=0;
   for (int i=b[0];i;i--)
   {
      int x=t*10+b[i];
      b[i]=x>>1;
      t=x&1;
   }
   while (!b[b[0]])
      b[0]--;
   return(t);
}
