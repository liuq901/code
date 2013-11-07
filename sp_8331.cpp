#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef long long ll;
const int mod=100000007;
bool vis[410][410][2];
ll f[410][410][2];
int l[410],r[410],b[410],d[410],a[810][2];
int main()
{
   void build(int,int),dfs(int),dp(int,int,int);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n,K;
      scanf("%d%*d%d",&n,&K);
      memset(b,0,sizeof(b));
      for (int i=1;i<n;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         a[i][0]=y,a[i][1]=b[x],b[x]=i;
         a[i+n][0]=x,a[i+n][1]=b[y],b[y]=i+n;
      }
      memset(l,0,sizeof(l));
      memset(r,0,sizeof(r));
      memset(d,0,sizeof(d));
      build(1,0);
      for (int i=1;i<=n;i++)
         dfs(l[i]);
      memset(vis,0,sizeof(vis));
      dp(1,K,1);
      printf("%lld\n",f[1][K][1]);
   }
   system("pause");
   return(0);
}
void build(int x,int father)
{
   int p;
   d[x]=1;
   for (int i=b[x];i;i=a[i][1])
   {
      int y=a[i][0];
      if (y==father)
         continue;
      if (!l[x])
         l[x]=y,p=y;
      else
         r[p]=y,p=r[p];
      build(y,x);
      d[x]+=d[y];
   }
}
void dfs(int x)
{
   if (!r[x])
      return;
   dfs(r[x]);
   d[x]+=d[r[x]];
}
void dp(int i,int j,int k)
{
   if (vis[i][j][k])
      return;
   vis[i][j][k]=true;
   ll &ret=f[i][j][k];
   if (!j)
      ret=1;
   else if (!i || d[i]+1>>1<j)
      ret=0;
   else if (!k)
   {
      ret=0;
      for (int p=0;p<=j;p++)
      {
         if (p>=1)
         {
            dp(l[i],p-1,1),dp(r[i],j-p,1);
            ret+=f[l[i]][p-1][1]*f[r[i]][j-p][1];
         }
         dp(l[i],p,0),dp(r[i],j-p,0);
         ret+=f[l[i]][p][0]*f[r[i]][j-p][0];
      }
   }
   else
   {
      ret=0;
      for (int p=0;p<=j;p++)
      {
         dp(l[i],p,0),dp(r[i],j-p,1);
         ret+=f[l[i]][p][0]*f[r[i]][j-p][1];
      }
   }
   ret%=mod;
   return;
}
