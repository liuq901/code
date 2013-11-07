#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int tot,l[30010],r[30010],dep[30010],pos[30010],e[60010],f[18][60010];
int main()
{
   void dfs(int);
   int log(int);
   int n,m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=n;i++)
      while (1)
      {
         int x;
         scanf("%d",&x);
         if (!x)
            break;
         if (!l[i])
         {
            l[i]=x;
            continue;
         }
         int p=l[i];
         while (r[p])
            p=r[p];
         r[p]=x;
      }
   tot=dep[1]=0;
   dfs(1);
   for (int i=1;i<=tot;i++)
      f[0][i]=i;
   for (int i=1;i<=log(tot);i++)
      for (int j=1;j<=tot;j++)
      {
         if (j+(1<<i)-1>tot)
            break;
         int p=f[i-1][j],q=f[i-1][j+(1<<i-1)];
         f[i][j]=dep[e[p]]<dep[e[q]]?p:q;
      }
   while (m--)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      int l=pos[x],r=pos[y];
      if (l>r)
         swap(l,r);
      int t=log(r-l+1);
      int p=f[t][l],q=f[t][r-(1<<t)+1];
      int ans=dep[e[p]]<dep[e[q]]?e[p]:e[q];
      printf("%d %d\n",ans,dep[x]+dep[y]-(dep[ans]<<1));
   }
   system("pause");
   return(0);
}
void dfs(int x)
{
   e[++tot]=x;
   pos[x]=tot;
   for (int i=l[x];i;i=r[i])
   {
      dep[i]=dep[x]+1;
      dfs(i);
      e[++tot]=x;
   }
}
int log(int x)
{
   int ans=-1;
   while (x)
   {
      ans++;
      x>>=1;
   }
   return(ans);
}
