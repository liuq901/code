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
int m;
ll f[10][520];
int main()
{
   void search(int,int,int,int,int,ll);
   int n;
   scanf("%d%d",&n,&m);
   f[0][(1<<m)-1]=1;
   for (int i=1;i<=n;i++)
      for (int j=0;j<1<<m;j++)
         if (f[i-1][j])
            search(i,j,0,0,0,f[i-1][j]);
   cout<<f[n][(1<<m)-1]<<endl;
   system("pause");
   return(0);
}
void search(int row,int up,int col,int state,int should,ll value)
{
   if (col>=2)
      should=(should<<1)+1;
   if ((up&should)!=should)
      return;
   if (col==m)
   {
      if (up==(1<<m)-1)
         f[row][state]+=value;
      return;
   }
   search(row,up,col+1,state,should,value);
   if (!(up>>col&1))
      search(row,up+(1<<col),col+1,state+(1<<col),should,value);
   if (col>=1 && !(up>>col&1) && !(up>>col-1&1))
      search(row,up+(1<<col)+(1<<col-1),col+1,state+(1<<col),should,value);
   if (col<=m-2)
   {
      search(row,up,col+2,state+(1<<col)+(1<<col+1),should,value);
      if (!(up>>col&1) && !(up>>col+1&1))
         search(row,up+(1<<col)+(1<<col+1),col+1,state+(1<<col),should,value);
      if (!(up>>col&1))
         search(row,up+(1<<col),col+2,state+(1<<col)+(1<<col+1),should,value);
      if (!(up>>col+1&1))
         search(row,up+(1<<col+1),col+2,state+(1<<col)+(1<<col+1),should,value);
   }
}
