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
#define map _map
#define SQR(x) ((x)*(x))
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
int n,tot,b[810],link[810],map[50][50],a[100010][2];
bool f[810];
int main()
{
   bool hungary(int);
   void print();
   int m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=m;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      map[x][y]=-1;
   }
   int t1=0,t2=0,t=0;
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
      {
         if (map[i][j]==-1)
            continue;
         if (i+j&1)
            map[i][j]=++t1;
         else
            map[i][j]=++t2;
      }
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
      {
         if (map[i][j]==-1)
            continue;
         if (i+j&1)
         {
            if (map[i-1][j]>0)
               a[++t][0]=map[i-1][j],a[t][1]=b[map[i][j]],b[map[i][j]]=t;
            if (map[i][j-1]>0)
               a[++t][0]=map[i][j-1],a[t][1]=b[map[i][j]],b[map[i][j]]=t;
            if (map[i+1][j]>0)
               a[++t][0]=map[i+1][j],a[t][1]=b[map[i][j]],b[map[i][j]]=t;
            if (map[i][j+1]>0)
               a[++t][0]=map[i][j+1],a[t][1]=b[map[i][j]],b[map[i][j]]=t;
         }
      }
   if (t1!=t2)
      printf("No\n");
   else
   {
      int ans=0;
      for (int i=1;i<=t1;i++)
      {
         memset(f,0,sizeof(f));
         ans+=hungary(i);
      }
      if (ans!=t1)
         printf("No\n");
      else
      {
         printf("Yes\n");
         print();
      }
   }
   system("pause");
   return(0);
}
bool hungary(int x)
{
   if (!x)
      return(true);
   for (int i=b[x];i;i=a[i][1])
   {
      int y=a[i][0];
      if (f[y])
         continue;
      f[y]=true;
      if (hungary(link[y]))
      {
         link[y]=x;
         return(true);
      }
   }
   return(false);
}
int ans1[810][2],ans2[810][2];
void print()
{
   int sum1,sum2;
   sum1=sum2=0;
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
      {
         if (map[i][j]==-1)
            continue;
         if (!(i+j&1))
         {
            int t=link[map[i][j]];
            if (t==map[i][j-1])
               ans2[++sum2][0]=i,ans2[sum2][1]=j-1;
            else if (t==map[i][j+1])
               ans2[++sum2][0]=i,ans2[sum2][1]=j;
            else if (t==map[i-1][j])
               ans1[++sum1][0]=i-1,ans1[sum1][1]=j;
            else
               ans1[++sum1][0]=i,ans1[sum1][1]=j;
         }
      }
   printf("%d\n",sum1);
   for (int i=1;i<=sum1;i++)
      printf("%d %d\n",ans1[i][0],ans1[i][1]);
   printf("%d\n",sum2);
   for (int i=1;i<=sum2;i++)
      printf("%d %d\n",ans2[i][0],ans2[i][1]);
}
