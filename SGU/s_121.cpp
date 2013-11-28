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
int a[110][110];
bool vis[110],color[110][110];
int main()
{
   bool work(int);
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      while (1)
      {
         int x;
         scanf("%d",&x);
         if (!x)
            break;
         a[i][++a[i][0]]=x;
      }
   bool flag=true;
   for (int i=1;i<=n;i++)
   {
      if (vis[i])
         continue;
      if (!work(i))
      {
         flag=false;
         break;
      }
   }
   if (!flag)
      printf("No solution\n");
   else
      for (int i=1;i<=n;i++)
      {
         for (int j=1;j<=a[i][0];j++)
         {
            int x=a[i][j];
            printf("%d ",color[i][x]?1:2);
         }
         printf("0\n");
      }
   system("pause");
   return(0);
}
int father[110],dep[110],l[110],r[110];
bool work(int root)
{
   void dfs(int),work(int,int),did(int);
   dfs(root);
   if (!l[root])
      return(true);
   if (r[l[root]])
   {
      for (int i=l[root];i;i=r[i])
      {
         if (i==l[root])
         {
            color[root][i]=color[i][root]=false;
            work(i,1);
            continue;
         }
         color[root][i]=color[i][root]=true;
         work(i,0);
      }
      return(true);
   }
   did(root);
   if (a[root][0]==1)
      return(true);
   for (int i=1;i<=a[root][0];i++)
   {
      int x=a[root][i];
      if (!color[root][x])
         return(true);
   }
   for (int i=1;i<=a[root][0];i++)
   {
      int x=a[root][i];
      if (l[x] && father[x]!=root)
      {
         bool tmp=color[root][x];
         color[root][x]=color[x][root]=!tmp;
         return(true);
      }
   }
   int i=root;
   while (l[i])
   i=l[i];
   int t=i;
   while (t && (t==i || a[t][0]<=2))
      t=father[t];
   if (!t)
      return(false);
   for (int j=i;j!=t;j=father[j])
   {
      int x=father[j];
      bool tmp=color[j][x];
      color[j][x]=color[x][j]=!tmp;
   }
   bool tmp=color[root][i];
   color[root][i]=color[i][root]=!tmp;
   return(true);
}
void dfs(int x)
{
   vis[x]=true;
   for (int i=1;i<=a[x][0];i++)
   {
      int y=a[x][i];
      if (vis[y])
         continue;
      father[y]=x;
      dep[y]=dep[x]+1;
      if (!l[x])
         l[x]=y;
      else
      {
         int p=l[x];
         while (r[p])
            p=r[p];
         r[p]=y;
      }
      dfs(y);
   }
}
void work(int x,int add)
{
   for (int i=1;i<=a[x][0];i++)
   {
      int y=a[x][i];
      if (y==father[x])
         continue;
      if (father[y]==x)
      {
         color[x][y]=color[y][x]=dep[y]+add&1;
         work(y,add);
      }
      else if (dep[y]<dep[x])
         color[x][y]=color[y][x]=!color[x][father[x]];
   }
}
void did(int x)
{
   for (int i=1;i<=a[x][0];i++)
   {
      int y=a[x][i];
      if (y==father[x])
         continue;
      if (father[y]==x)
      {
         color[x][y]=color[y][x]=dep[y]&1;
         did(y);
      }
      else if (dep[y]<dep[x])
         color[x][y]=color[y][x]=dep[x]+1&1;
   }
}
