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
int id,a[1100][1100];
int main()
{
   void work(int,int,int,int,int);
   int n,x,y;
   scanf("%d%d%d",&n,&x,&y);
   work(1,1,x,y,1<<n);
   for (int i=1;i<=1<<n;i++)
   {
      for (int j=1;j<1<<n;j++)
         printf("%d ",a[i][j]);
      printf("%d\n",a[i][1<<n]);
   }
   system("pause");
   return(0);
}
void work(int x,int y,int x0,int y0,int size)
{
   if (size==2)
   {
      id++;
      for (int i=0;i<=1;i++)
         for (int j=0;j<=1;j++)
         {
            int p=x+i,q=y+j;
            if (p==x0 && q==y0)
               continue;
            a[p][q]=id;
         }
      return;
   }
   int t=size>>1,now=++id;
   if (x0<x+t && y0<y+t)
      work(x,y,x0,y0,size>>1);
   else
   {
      a[x+t-1][y+t-1]=now;
      work(x,y,x+t-1,y+t-1,size>>1);
   }
   if (x0<x+t && y0>=y+t)
      work(x,y+t,x0,y0,size>>1);
   else
   {
      a[x+t-1][y+t]=now;
      work(x,y+t,x+t-1,y+t,size>>1);
   }
   if (x0>=x+t && y0<y+t)
      work(x+t,y,x0,y0,size>>1);
   else
   {
      a[x+t][y+t-1]=now;
      work(x+t,y,x+t,y+t-1,size>>1);
   }
   if (x0>=x+t && y0>=y+t)
      work(x+t,y+t,x0,y0,size>>1);
   else
   {
      a[x+t][y+t]=now;
      work(x+t,y+t,x+t,y+t,size>>1);
   }
}
