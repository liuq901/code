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
typedef map <char,int>::iterator data;
const int inf=1061109567;
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
string a[15];
int ans,n,now,l[15],P[260];
bool f[11],g[260];
int main()
{
   void dfs(int,int);
   while (1)
   {
      scanf("%d",&n);
      if (!n)
         break;
      for (int i=1;i<=n;i++)
      {
         cin>>a[i];
         l[i]=a[i].size();
      }
      ans=now=0;
      for (int i=1;i<=n-1;i++)
         if (l[i]>l[n])
         {
            ans=-1;
            break;
         }
      memset(f,0,sizeof(f));
      memset(g,0,sizeof(g));
      if (ans!=-1)
         dfs(1,1);
      if (ans==-1)
         ans=0;
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
void dfs(int dep,int x)
{
   if (dep==l[n]+1)
   {
      if (!now)
         ans++;
      return;
   }
   int p=l[x]-dep;
   if (p<0)
   {
      dfs(dep,x+1);
      return;
   }
   char ch=a[x][p];
   int t=now;
   if (x==n)
   {
      int last=now%10;
      if (g[ch] && P[ch]!=last)
         return;
      if (!g[ch] && f[last])
         return;
      if (l[x]>1 && !last && !p)
         return;
      bool flag=true;
      if (!f[last])
         flag=false,f[last]=true,P[ch]=last,g[ch]=true;
      now/=10;
      dfs(dep+1,1);
      now=t;
      if (!flag)
      {
         f[last]=false;
         g[ch]=false;
      }
      return;
   }
   if (g[ch])
   {
      now+=P[ch];
      if (l[x]>1 && !P[ch] && !p)
         return;
      dfs(dep,x+1);
      now=t;
      return;
   }
   for (int i=0;i<10;i++)
   {
      if (l[x]>1 && !i && !p)
         continue;
      if (f[i])
         continue;
      f[i]=true;
      g[ch]=true;
      P[ch]=i;
      now+=i;
      dfs(dep,x+1);
      f[i]=false;
      g[ch]=false;
      now=t;
   }
}
