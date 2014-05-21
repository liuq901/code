#include <cstdio>
#include <cstring>
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int tot,b[210],d[210],to[30][30],a[100000][2];
char s[30][30];
bool vis[210];
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
        if (vis[y])
            continue;
        vis[y]=true;
        if (hungary(d[y]))
        {
            d[y]=x;
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
            scanf("%s",s[i]+1);
        int cnt[2]={0};
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                if (s[i][j]=='*')
                    to[i][j]=++cnt[i+j&1];
        memset(b,0,sizeof(b));
        tot=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                if (i+j&1 && s[i][j]=='*')
                    for (int k=0;k<4;k++)
                    {
                        int x=i+c[k][0],y=j+c[k][1];
                        if (x>0 && x<=n && y>0 && y<=m && s[x][y]=='*')
                            add(to[i][j],to[x][y]);
                    }
        memset(d,0,sizeof(d));
        int ans=cnt[0]+cnt[1];
        for (int i=1;i<=cnt[1];i++)
        {
            memset(vis,0,sizeof(vis));
            ans-=hungary(i);
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

