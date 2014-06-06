#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int n,m,ans,f[2][131080];
bool in[2][131080];
char a[110][10];
queue <int> q[2];
inline bool empty(int x,int y)
{
    return(!(x>>y&1));
}
inline void update(int id,int x,int y)
{
    if (!in[id][x])
    {
        in[id][x]=true;
        q[id].push(x);
    }
    f[id][x]=max(f[id][x],y);
}
void dfs(int x,int y,int u)
{
    if (y==m+1)
    {
        dfs(x+1,1,u);
        return;
    }
    if (x==n+1)
    {
        while (!q[u].empty())
        {
            ans=max(ans,f[u][q[u].front()]);
            f[u][q[u].front()]=0;
            in[u][q[u].front()]=false;
            q[u].pop();
        }
        return;
    }
    int v=u^1;
    while (!q[u].empty())
    {
        int state=q[u].front(),value=f[u][state];
        q[u].pop();
        if (a[x][y]=='#')
            update(v,state>>1|1<<2*m,value);
        else
        {
            update(v,state>>1,value);
            if (y>=3 && empty(state,m-1) && empty(state,m) && empty(state,m+1) && empty(state,2*m-1) && empty(state,2*m))
                update(v,state>>1|1<<m-2|1<<m-1|1<<m|1<<2*m-2|1<<2*m-1|1<<2*m,value+1);
            if (y>=2 && empty(state,0) && empty(state,1) && empty(state,m) && empty(state,m+1) && empty(state,2*m))
                update(v,state>>1|1|1<<m-1|1<<m|1<<2*m-1|1<<2*m,value+1);
        }
        f[u][state]=0;
        in[u][state]=false;
    }
    dfs(x,y+1,v);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&m,&n);
        for (int j=1;j<=m;j++)
            for (int i=1;i<=n;i++)
                scanf(" %c",&a[i][j]);
        q[0].push((1<<2*m+1)-1);
        in[0][(1<<2*m+1)-1]=true;
        ans=0;
        dfs(1,1,0);
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

