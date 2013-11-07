#include <cstdio>
#include <cstdlib>
#include <cstring>
int f[1001],g[1001],dep[1001],a[1001][26];
int main()
{
   void count(int,int),dfs(int,int);
   int n,k,i,x,y;
   scanf("%d%d",&n,&k);
   for (i=1;i<=n;i++)
      a[i][0]=0;
   for (i=1;i<=n-1;i++)
   {
      scanf("%d%d",&x,&y);
      a[x][0]++;
      a[x][a[x][0]]=y;
      a[y][0]++;
      a[y][a[y][0]]=x;
   }
   dep[0]=-1;
   memset(f,0,sizeof(f));
   count(k,0);
   dfs(k,0);
   if (!g[k])
      printf("First player loses\n");
   else
      printf("First player wins flying to airport %d\n",g[k]);
   system("pause");
   return(0);
}
void count(int x,int father)
{
   int i;
   dep[x]=dep[father]+1;
   for (i=1;i<=a[x][0];i++)
   {
      if (a[x][i]==father)
         continue;
      f[x]=1;
      count(a[x][i],x);
   }
}
void dfs(int x,int father)
{
   int i;
   if (!f[x])
   {
      g[x]=0;
      return;
   }
   g[x]=20000000;
   for (i=1;i<=a[x][0];i++)
   {
      if (a[x][i]==father)
         continue;
      dfs(a[x][i],x);
      if (!g[a[x][i]] && a[x][i]<g[x])
         g[x]=a[x][i];
   }
   if (g[x]==20000000)
      g[x]=0;
}
