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
int m,a[80],f[2][130][130];
int main()
{
   void search(int,int,int,int,int,int);
   int n;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
      {
         char ch;
         cin>>ch;
         a[i]=(a[i]<<1)+(ch=='*');
      }
   memset(f,63,sizeof(f));
   f[0][(1<<m)-1][(1<<m)-1]=0;
   for (int i=1;i<=n;i++)
      for (int j=0;j<1<<m;j++)
         for (int k=0;k<1<<m;k++)
         {
            if (f[i-1&1][j][k]==inf)
               continue;
            search(i,0,0,j,k,f[i-1&1][j][k]);
            f[i-1&1][j][k]=inf;
         }
   int ans=inf;
   for (int i=0;i<1<<m;i++)
   {
      int t=i,b[10];
      for (int j=1;j<=m;j++)
      {
         b[j]=t&1;
         t>>=1;
      }
      bool flag=true;
      for (int j=1;j<m;j++)
         if (!b[j] && !b[j+1])
         {
            flag=false;
            break;
         }
      if (!flag)
         continue;
      for (int j=0;j<1<<m;j++)
      {
         flag=true;
         t=j;
         int c[10];
         for (int k=1;k<=m;k++)
         {
            c[k]=t&1;
            t>>=1;
            if (!b[k] && !c[k])
            {
               flag=false;
               break;
            }
         }
         if (flag)
            ans=min(ans,f[n&1][i][j]);
      }
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void search(int row,int col,int state,int up,int top,int value)
{
   if (state&a[row] || col>=2 && !(up>>col-2&1) && !(up>>col-1&1) || col && !(up>>col-1&1) && !(top>>col-1&1))
      return;
   if (col==m)
   {
      state|=a[row];
      f[row&1][state][up]=min(f[row&1][state][up],value);
      return;
   }
   search(row,col+1,state,up,top,value);
   if (!(up>>col&1))
      search(row,col+1,state+(1<<col),up+(1<<col),top,value+1);
   if (col<=m-2 && (!col || (up>>col-1&1)+(up>>col&1)) && (up>>col&1)+(top>>col&1))
      search(row,col+2,state+(1<<col)+(1<<col+1),up,top,value+1);
}
