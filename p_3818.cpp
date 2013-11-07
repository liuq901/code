#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int mod=1000000;
int origin,n,u,v,cnt[2],q[2][1100],f[2][1100];
bool vis[1100];
vector <int> b[1100];
inline void update(int now,int value)
{
    if (f[v][now]==-1)
    {
        f[v][now]=0;
        q[v][++cnt[v]]=now;
    }
    f[v][now]=(f[v][now]+value)%mod;
}
inline bool state(int x,int y)
{
    return(x>>y&1);
}
void dfs(int up,int now,int pos)
{
    if (pos==n)
    {
        b[origin].push_back(now);
        return;
    }
    if (pos<n && state(up,pos))
        dfs(up,now,pos+1);
    if (pos+1<n && state(up,pos) && !state(up,pos+1) && !state(now,pos) && !state(up,pos+1))
        dfs(up|1<<pos+1,now|1<<pos|1<<pos+1,pos+1);
    if (pos+1<n && !state(up,pos) && !state(now,pos) && !state(now,pos+1))
        dfs(up|1<<pos,now|1<<pos|1<<pos+1,pos+1);
    if (pos+1<n && !state(up,pos) && !state(up,pos+1) && !state(now,pos+1))
        dfs(up|1<<pos|1<<pos+1,now|1<<pos+1,pos+1);
    if (pos+1<n && !state(up,pos) && !state(up,pos+1) && !state(now,pos))
        dfs(up|1<<pos|1<<pos+1,now|1<<pos,pos+1);
    if (pos+1<n && !state(up,pos) && !state(up,pos+1) && !state(now,pos) && !state(now,pos+1))
        dfs(up|1<<pos|1<<pos+1,now|1<<pos|1<<pos+1,pos+1);
}
int main()
{
    while (1)
    {
        int m;
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        u=0,v=1;
        cnt[u]=1;
        q[u][1]=0;
        f[u][0]=1;
        memset(vis,0,sizeof(vis));
        for (int i=0;i<1<<n;i++)
            b[i].clear();
        for (int i=1;i<m;i++)
        {
            cnt[v]=0;
            memset(f[v],-1,sizeof(f[v]));
            for (int j=1;j<=cnt[u];j++)
            {
                int x=q[u][j];
                if (!vis[x])
                {
                    origin=x;
                    dfs(x,0,0);
                    vis[x]=true;
                }
                for (int k=0;k<b[x].size();k++)
                    update(b[x][k],f[u][x]);
            }
            u^=1,v^=1;
        }
        printf("%d\n",max(f[u][(1<<n)-1],0));
    }
    return(0);
}

