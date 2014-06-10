#include <cstdio>
#include <cstring>
bool f[500010];
int m,p[500010];
void init()
{
    const int n=500000;
    for (int i=2;i*i<=n;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=n;j++)
            f[i*j]=true;
    }
    for (int i=2;i<=n;i++)
        if (!f[i])
            p[++m]=i;
}
int tot,b[40010],a[2600000][2];
void add(int x,int y)
{
    a[++tot][0]=y,a[tot][1]=b[x],b[x]=tot;
}
int n,wh[40010],from[40010],dx[40010],dy[40010],q[40010];
bool bfs()
{
    bool ret=false;
    int h=0,t=0;
    for (int i=0;i<n;i++)
        if (wh[i]==-1)
            q[++t]=i;
    memset(dx,0,sizeof(dx));
    memset(dy,0,sizeof(dy));
    while (h<t)
    {
        int x=q[++h];
        for (int i=b[x];i;i=a[i][1])
        {
            int y=a[i][0];
            if (dy[y]==0)
            {
                dy[y]=dx[x]+1;
                if (from[y]==-1)
                    ret=true;
                else
                {
                    dx[from[y]]=dx[x]+2;
                    q[++t]=from[y];
                }
            }
        }
    }
    return(ret);
}
bool dfs(int x)
{
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (dy[y]==dx[x]+1)
        {
            dy[y]=0;
            if (from[y]==-1 || dfs(from[y]))
            {
                wh[x]=y;
                from[y]=x;
                return(true);
            }
        }
    }
    return(false);
}
int hopcroft()
{
    memset(from,-1,sizeof(from));
    memset(wh,-1,sizeof(wh));
    int ans=0;
    while (bfs())
        for (int i=0;i<n;i++)
            if (wh[i]==-1 && dfs(i))
                ans++;
    return(ans);
}
int cnt[500010];
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        memset(cnt,-1,sizeof(cnt));
        for (int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            cnt[x]=i;
        }
        const int N=500000;
        memset(b,0,sizeof(b));
        tot=0;
        for (int i=1;i<=N;i++)
        {
            if (cnt[i]==-1)
                continue;
            for (int j=1;j<=m;j++)
            {
                if (i*p[j]>N)
                    break;
                if (cnt[i*p[j]]!=-1)
                {
                    add(cnt[i],cnt[i*p[j]]);
                    add(cnt[i*p[j]],cnt[i]);
                }
            }
        }
        static int id=0;
        printf("Case %d: %d\n",++id,n-hopcroft()/2);
    }
    return(0);
}

