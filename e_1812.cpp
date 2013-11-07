#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int ans,l[10010],r[10010],f[10010];
int main()
{
   void dfs(int,int);
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      scanf("%d%d",&l[i],&r[i]);
      f[l[i]]=f[r[i]]=i;
   }
   for (int i=1;i<=n;i++)
      if (!f[i])
      {
         dfs(i,1);
         break;
      }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void dfs(int x,int dep)
{
   if (!x)
      return;
   ans=max(ans,dep);
   dfs(l[x],dep+1),dfs(r[x],dep+1);
}
