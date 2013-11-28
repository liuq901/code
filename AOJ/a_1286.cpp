#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;
int n,m,k;
ll ans;
int main()
{
   void dfs(int,int);
   while (1)
   {
      scanf("%d%d%d",&n,&m,&k);
      if (!n && !m && !k)
         break;
      ans=0;
      dfs(1,0);
      ll p=1;
      for (int i=1;i<=n;i++)
         p*=m;
      printf("%.10f\n",double(ans)/p);
   }
   system("pause");
   return(0);
}
void dfs(int dep,int sum)
{
   if (dep==n+1)
   {
      ans+=max(1,sum-k);
      return;
   }
   for (int i=1;i<=m;i++)
      dfs(dep+1,sum+i);
}
