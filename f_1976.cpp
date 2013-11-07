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
#define MAXN 1010
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
const int f[12][20]={
   {1,2,1,0,2,4,3,2,3,6,5,4,4,8,7,6,5,0,9,8},
   {0,6,5,4,5,8,7,6,10,8,7,6,6,8,7,6,2,6,5,4},
   {3,8,7,6,0,8,7,6,1,0,9,8,6,6,5,4,7,6,5,4},
   {4,0,9,8,0,0,9,8,2,2,1,0,7,4,3,2,8,4,3,2},
   {5,2,1,0,0,2,1,0,3,4,3,2,8,2,1,0,9,2,1,0},
   {1,4,3,2,0,4,3,2,4,6,5,4,9,0,9,8,10,0,9,8},
   {10,6,5,4,11,8,7,6,7,8,7,6,2,8,7,6,1,8,7,6},
   {6,4,3,2,11,6,5,4,8,6,5,4,3,0,9,8,2,0,9,8},
   {7,2,1,0,11,4,3,2,9,4,3,2,4,2,1,0,3,2,1,0},
   {8,0,9,8,11,2,1,0,10,2,1,0,5,4,3,2,4,4,3,2},
   {9,8,7,6,11,0,9,8,6,0,9,8,1,6,5,4,5,6,5,4},
   {10,4,3,2,9,6,5,4,8,8,7,6,7,0,9,8,6,2,1,0}};
int a[12][11];
int main()
{
   void work(int,int);
   int test;
   scanf("%d",&test);
   for (int id=1;id<=test;id++)
   {
      for (int i=0;i<12;i++)
         for (int j=0;j<11;j++)
            a[i][j]=i;
      int n;
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         work(x,y);
      }
      printf("Case %d:\n",id);
      for (int i=0;i<12;i++)
      {
         for (int j=0;j<10;j++)
            printf("%d ",a[i][j]);
         printf("%d\n",a[i][10]);
      }
   }
   system("pause");
   return(0);
}
void work(int p,int order)
{
   if (order==1)
   {
      int x,y,z,k;
      k=f[p][16];
      x=a[k][f[p][17]],y=a[k][f[p][18]],z=a[k][f[p][19]];
      for (int i=16;i>=4;i-=4)
      {
         int k=f[p][i],q=f[p][i-4];
         a[k][f[p][i+1]]=a[q][f[p][i-3]];
         a[k][f[p][i+2]]=a[q][f[p][i-2]];
         a[k][f[p][i+3]]=a[q][f[p][i-1]];
      }
      k=f[p][0];
      a[k][f[p][1]]=x,a[k][f[p][2]]=y,a[k][f[p][3]]=z;
      x=a[p][8],y=a[p][9];
      for (int i=8;i>=2;i-=2)
         a[p][i]=a[p][i-2],a[p][i+1]=a[p][i-1];
      a[p][0]=x,a[p][1]=y;
   }
   else
   {
      int x,y,z,k;
      k=f[p][0];
      x=a[k][f[p][1]],y=a[k][f[p][2]],z=a[k][f[p][3]];
      for (int i=0;i<=12;i+=4)
      {
         int k=f[p][i],q=f[p][i+4];
         a[k][f[p][i+1]]=a[q][f[p][i+5]];
         a[k][f[p][i+2]]=a[q][f[p][i+6]];
         a[k][f[p][i+3]]=a[q][f[p][i+7]];
      }
      k=f[p][16];
      a[k][f[p][17]]=x,a[k][f[p][18]]=y,a[k][f[p][19]]=z;
      x=a[p][0],y=a[p][1];
      for (int i=0;i<=6;i+=2)
         a[p][i]=a[p][i+2],a[p][i+1]=a[p][i+3];
      a[p][8]=x,a[p][9]=y;
   }
}
