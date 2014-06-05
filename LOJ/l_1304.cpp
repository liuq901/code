#include <cstdio>
#include <cstring>
char grid[110][110];
int idx,tot,row[110][110],column[110][110],b[10010],to[10010],vis[10010],a[1000000][2];
void add(int x,int y)
{
    a[++tot][0]=y,a[tot][1]=b[x],b[x]=tot;
}
bool hungary(int x)
{
    if (x==0)
        return(true);
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (vis[y]==idx)
            continue;
        vis[y]=idx;
        if (hungary(to[y]))
        {
            to[y]=x;
            return(true);
        }
    }
    return(false);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            scanf("%s",grid[i]+1);
        int t=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                if (j==1 || grid[i][j-1]=='W')
                    t++;
                row[i][j]=t;
            }
        int N=t;
        t=0;
        for (int j=1;j<=m;j++)
            for (int i=1;i<=n;i++)
            {
                if (i==1 || grid[i-1][j]=='W')
                    t++;
                column[i][j]=t;
            }
        memset(b,0,sizeof(b));
        tot=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                if (grid[i][j]=='.')
                    add(row[i][j],column[i][j]);
        memset(to,0,sizeof(to));
        int ans=0;
        for (int i=1;i<=N;i++)
        {
            idx++;
            ans+=hungary(i);
        }
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                if (grid[i][j]=='.' && row[i][j]==to[column[i][j]])
                    grid[i][j]='T';
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
        for (int i=1;i<=n;i++)
            printf("%s\n",grid[i]+1);
    }
    return(0);
}

