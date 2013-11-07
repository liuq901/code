#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
struct edge
{
   int id,len,x,y;
   edge(){}
   edge(int id,int len,int x,int y):id(id),len(len),x(x),y(y){}
};
bool operator <(edge a,edge b)
{
   return(a.len<b.len || a.len==b.len && a.id<b.id);
}
edge e[500010];
int n,c[50010],f[50010],b[50010],a[100010][3];
ll best,dis[50010],sum[50010],dep[50010];
int main()
{
   int find(int);
   void dfs(int,int),dp(int,int);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int m;
      scanf("%d%d",&n,&m);
      for (int i=1;i<=m;i++)
      {
         int x,y,len;
         scanf("%d%d%d",&x,&y,&len);
         e[i]=edge(i,len,x,y);
      }
      sort(e+1,e+m+1);
      int tot=0;
      for (int i=1;i<=n;i++)
         f[i]=i;
      for (int i=1;i<=m;i++)
      {
         int x=e[i].x,y=e[i].y;
         if (find(x)==find(y))
            continue;
         c[++tot]=i;
         f[find(x)]=find(y);
         if (tot==n-1)
            break;
      }
      if (tot!=n-1)
         printf("Poor mayor.\n");
      else
      {
         memset(b,0,sizeof(b));
         int ans=0;
         for (int i=1;i<=tot;i++)
         {
            int p=c[i],x=e[p].x,y=e[p].y,len=e[p].len;
            a[i][0]=x,a[i][1]=len<<1,a[i][2]=b[y],b[y]=i;
            a[i+tot][0]=y,a[i+tot][1]=len<<1,a[i+tot][2]=b[x],b[x]=i+tot;
            ans+=len;
         }
         printf("%d\n",ans);
         best=1LL<<60;
         memset(sum,0,sizeof(sum));
         memset(c,0,sizeof(c));
         dis[1]=0;
         dfs(1,0);
         dp(1,0);
         bool first=true;
         for (int i=1;i<=n;i++)
            if (best==dep[i])
            {
               if (!first)
                  printf(" ");
               first=false;
               printf("%d",i);
            }
         printf("\n");
         cout<<best<<endl;
      }
   }
   system("pause");
   return(0);
}
int find(int x)
{
   if (x!=f[x])
      f[x]=find(f[x]);
   return(f[x]);
}
void dfs(int x,int father)
{
   sum[x]=0;
   c[x]=1;
   for (int i=b[x];i;i=a[i][2])
   {
      int y=a[i][0];
      if (y==father)
         continue;
      dfs(y,x);
      c[x]+=c[y];
      sum[x]+=sum[y]+ll(a[i][1])*c[y];
   }
}
void dp(int x,int father)
{
   dep[x]=dis[x]+sum[x];
   best=min(best,dep[x]);
   for (int i=b[x];i;i=a[i][2])
   {
      int y=a[i][0];
      if (y==father)
         continue;
      dis[y]=dep[x]-sum[y]+ll(a[i][1])*(n-2*c[y]);
      dp(y,x);
   }
}
