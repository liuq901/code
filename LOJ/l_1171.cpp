#include <cstdio>
#include <cstring>
const int c[8][2]={{-1,2},{-1,-2},{1,-2},{1,2},{2,-1},{2,1},{-2,-1},{-2,1}};
int tot,b[20010],a[1000000][2],cnt[210][210];
void add(int x,int y)
{
    a[++tot][0]=y,a[tot][1]=b[x],b[x]=tot;
}
int from[20010],wh[20010],q[20010],dx[20010],dy[20010];
bool bfs(int n)
{
    bool ret=false;
    int h=0,t=0;
    for (int i=1;i<=n;i++)
        if (wh[i]==0)
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
                if (from[y]==0)
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
            if (from[y]==0 || dfs(from[y]))
            {
                wh[x]=y;
                from[y]=x;
                return(true);
            }
        }
    }
    return(false);
}
int hopcroft(int n)
{
    int ans=0;
    memset(from,0,sizeof(from));
    memset(wh,0,sizeof(wh));
    while (bfs(n))
        for (int i=1;i<=n;i++)
            if (wh[i]==0 && dfs(i))
                ans++;
    return(ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        memset(cnt,0,sizeof(cnt));
        int n,m,K;
        scanf("%d%d%d",&n,&m,&K);
        for (int i=1;i<=K;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            cnt[x][y]=-1;
        }
        int t[2]={0};
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                if (cnt[i][j]!=-1)
                    cnt[i][j]=++t[i+j&1];
        memset(b,0,sizeof(b));
        tot=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                if (i+j&1 && cnt[i][j]!=-1)
                    for (int k=0;k<8;k++)
                    {
                        int x=i+c[k][0],y=j+c[k][1];
                        if (x>0 && x<=n && y>0 && y<=m && cnt[x][y]!=-1)
                            add(cnt[i][j],cnt[x][y]);
                    }
        static int id=0;
        printf("Case %d: %d\n",++id,n*m-K-hopcroft(t[1]));
    }
    return(0);
}

