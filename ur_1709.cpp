#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
#include <cstdarg>
#include <iostream>
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
const double eps=1e-7;
const double pi=acos(-1.0);
int f[101],edge[101],a[10001][3];
char c[101][101];
int main()
{
   void sort(int,int);
   int find(int);
   int n,del,add,tot=0;
   ll ans=0;
   scanf("%d%d%d",&n,&del,&add);
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
      {
         char ch;
         cin>>ch;
         c[i][j]=ch=='0'?'0':'d';
         if (i<j)
         {
            a[++tot][0]=i,a[tot][1]=j,a[tot][2]=ch=='1'?-del:add;
            ans+=ch=='1';
         }
      }
   sort(1,tot);
   for (int i=1;i<=n;i++)
      f[i]=i;
   int sum=0;
   ans*=del;
   for (int i=1;i<=tot;i++)
   {
      int x=find(a[i][0]),y=find(a[i][1]);
      if (x==y)
         continue;
      ans+=a[i][2];
      f[x]=y;
      edge[++sum]=i;
      if (sum==n-1)
         break;
   }
   cout<<ans<<endl;
   for (int i=1;i<n;i++)
   {
      int x=a[edge[i]][0],y=a[edge[i]][1],z=a[edge[i]][2];
      c[x][y]=c[y][x]=z<0?'0':'a';
   }
   for (int i=1;i<=n;i++)
   {
      for (int j=1;j<=n;j++)
         printf("%c",c[i][j]);
      printf("\n");
   }
   system("pause");
   return(0);
}
void sort(int l,int r)
{
   int i,j,x;
   i=l,j=r;
   x=a[l+r>>1][2];
   while (i<=j)
   {
      while (a[i][2]<x)
         i++;
      while (a[j][2]>x)
         j--;
      if (i<=j)
      {
         swap(a[i][0],a[j][0]);
         swap(a[i][1],a[j][1]);
         swap(a[i][2],a[j][2]);
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
int find(int x)
{
   if (x!=f[x])
      f[x]=find(f[x]);
   return(f[x]);
}
