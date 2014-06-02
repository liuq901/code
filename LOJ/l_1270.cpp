#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
char a[110][110],tmp[110][110];
void rotate(int &n,int &m)
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            tmp[j][n-i+1]=a[i][j];
    swap(n,m);
    memcpy(a,tmp,sizeof(tmp));
}
ull ans,f[2][520];
int n,m;
inline bool empty(int x,int pos)
{
    return(!(x>>pos&1));
}
void dfs(int x,int y,int u,int v)
{
    if (y==m+1)
    {
        dfs(x+1,1,u,v);
        return;
    }
    if (x==n+1)
    {
        ans+=f[u][(1<<m+1)-1];
        return;
    }
    memset(f[v],0,sizeof(f[v]));
    for (int i=0;i<1<<m+1;i++)
    {
        if (f[u][i]==0)
            continue;
        bool t=a[x][y]=='#';
        if (!empty(i,0))
            f[v][i>>1|t<<m]+=f[u][i];
        if (empty(i,1) && !empty(i,0) && !t)
            f[v][i>>1|1|1<<m]+=f[u][i];
        if (y>1 && empty(i,m) && !empty(i,0) && !t)
            f[v][i>>1|1<<m|1<<m-1]+=f[u][i];
        if (y>1 && empty(i,m) && empty(i,0) && !t)
            f[v][i>>1|1<<m|1<<m-1]+=f[u][i];
        if (y>1 && empty(i,0) && empty(i,1)&& empty(i,m))
            f[v][i>>1|1|1<<m-1|t<<m]+=f[u][i];
        if (y>1 && empty(i,1) && empty(i,m) && !empty(i,0) && !t)
            f[v][i>>1|1|1<<m-1|1<<m]+=f[u][i];
        if (y>1 && empty(i,0) && empty(i,1) && !t)
            f[v][i>>1|1|1<<m]+=f[u][i];
    }
    dfs(x,y+1,v,u);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            scanf("%s",a[i]+1);
        if (n<=8)
            rotate(n,m);
        memset(f,0,sizeof(f));
        f[0][(1<<m+1)-1]=1;
        ans=0;
        dfs(1,1,0,1);
        static int id=0;
        printf("Case %d: %llu\n",++id,ans);
    }
    return(0);
}

