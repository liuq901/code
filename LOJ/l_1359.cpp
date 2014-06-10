#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int d[100010],b[100010],a[1000010][3];
bool in[100010];
void spfa()
{
    memset(d,-1,sizeof(d));
    queue <int> Q;
    Q.push(1);
    d[1]=0;
    in[1]=true;
    while (!Q.empty())
    {
        int x=Q.front();
        in[x]=false;
        Q.pop();
        for (int i=b[x];i;i=a[i][2])
        {
            int y=a[i][0];
            if (d[y]==-1 || d[x]+a[i][1]<d[y])
            {
                d[y]=d[x]+a[i][1];
                if (!in[y])
                {
                    in[y]=true;
                    Q.push(y);
                }
            }
        }
    }
}
inline bool cmp(int x,int y)
{
    return(d[x]<d[y]);
}
int c[100010],dep[100010],cnt[100010],fa[100010][17];
int lca(int x,int y)
{
    if (dep[x]<dep[y])
        swap(x,y);
    for (int i=16;i>=0;i--)
        if (dep[fa[x][i]]>=dep[y])
            x=fa[x][i];
    if (x==y)
        return(x);
    for (int i=16;i>=0;i--)
        if (fa[x][i]!=fa[y][i])
            x=fa[x][i],y=fa[y][i];
    return(fa[x][0]);
}
void build(int n)
{
    for (int i=1;i<=n;i++)
        c[i]=i;
    sort(c+1,c+n+1,cmp);
    dep[1]=cnt[1]=1;
    for (int i=1;i<=n;i++)
    {
        int x=c[i];
        if (d[x]<=0)
            continue;
        cnt[x]=1;
        int t=-1;
        for (int j=b[x];j;j=a[j][2])
        {
            int y=a[j][0];
            if (d[y]+a[j][1]==d[x])
                t=t==-1?y:lca(t,y);
        }
        dep[x]=dep[t]+1;
        fa[x][0]=t;
        for (int i=1;i<=16;i++)
            fa[x][i]=fa[fa[x][i-1]][i-1];
    }
    for (int i=n;i;i--)
    {
        int x=c[i];
        if (d[x]<=0)
            break;
        cnt[fa[x][0]]+=cnt[x];
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            x++,y++;
            a[i][0]=y,a[i][1]=z,a[i][2]=b[x],b[x]=i;
            a[i+m][0]=x,a[i+m][1]=z,a[i+m][2]=b[y],b[y]=i+m;
        }
        spfa();
        build(n);
        int Q;
        scanf("%d",&Q);
        static int id=0;
        printf("Case %d:\n",++id);
        while (Q--)
        {
            int K,t=-1;
            scanf("%d",&K);
            for (int i=1;i<=K;i++)
            {
                int x;
                scanf("%d",&x);
                x++;
                if (d[x]==-1)
                    continue;
                t=t==-1?x:lca(t,x);
            }
            if (t==-1)
                printf("0\n");
            else
                printf("%d %d\n",dep[t],cnt[t]);
        }
    }
    return(0);
}

