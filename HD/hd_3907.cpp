#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dep[1010],q[1010],w[1010],s[1010],l[1010],r[1010],last[1010],f[1010][1010];
bool vis[1010][1010];
void add(int x,int y)
{
    if (!l[x])
        l[x]=y;
    else
        r[last[x]]=y;
    last[x]=y;
}
void dfs(int x)
{
    for (int i=l[x];i;i=r[i])
    {
        dep[i]=dep[x]+w[i];
        dfs(i);
    }
}
int calc(int x,int par)
{
    if (vis[x][par])
        return(f[x][par]);
    vis[x][par]=true;
    int &ret=f[x][par];
    ret=s[x];
    for (int i=l[x];i;i=r[i])
        ret+=calc(i,x);
    if (dep[x]-dep[par]<=q[x])
    {
        int sum=0;
        for (int i=l[x];i;i=r[i])
            sum+=calc(i,par);
        ret=min(ret,sum);
    }
    return(ret);
}
int main()
{
     int T;
     scanf("%d",&T);
     while (T--)
     {
         memset(l,0,sizeof(l));
         memset(r,0,sizeof(r));
         memset(vis,0,sizeof(vis));
         int n,root;
         scanf("%d",&n);
         for (int i=1;i<=n;i++)
         {
             int x;
             scanf("%d%d%d%d",&x,&q[i],&s[i],&w[i]);
             if (x==0)
                 root=i;
             else
                 add(x,i);
         }
         dep[root]=0;
         dfs(root);
         printf("%d\n",calc(root,root));
     }
     return(0);
}

