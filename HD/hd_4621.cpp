#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf=1<<30;
int S,T,tot,Log[60],b[230010],a[2000000][3],l[60][60][6][6],r[60][60][6][6];
void add(int x,int y,int c)
{
    a[++tot][0]=y,a[tot][1]=c,a[tot][2]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],b[y]=tot;
}
int d[230010],q[230010];
bool build()
{
    int l,r;
    q[l=r=1]=S;
    memset(d,0,sizeof(d));
    d[S]=1;
    while (l<=r)
    {
        int x=q[l++];
        for (int i=b[x];i;i=a[i][2])
        {
            int y=a[i][0];
            if (d[y] || !a[i][1])
                continue;
            d[y]=d[x]+1;
            q[++r]=y;
            if (y==T)
                return(true);
        }
    }
    return(false);
}
int dinic(int x,int flow)
{
    if (x==T)
        return(flow);
    int k=flow;
    for (int i=b[x];i;i=a[i][2])
    {
        int y=a[i][0];
        if (d[y]!=d[x]+1 || !a[i][1])
            continue;
        int t=dinic(y,min(k,a[i][1]));
        k-=t;
        a[i][1]-=t;
        a[i^1][1]+=t;
        if (k==0)
            break;
    }
    if (k==flow)
        d[x]=-1;
    return(flow-k);
}
int main()
{
    Log[1]=0;
    for (int i=2;i<=50;i++)
    {
        Log[i]=Log[i-1];
        if (i&i-1)
            continue;
        Log[i]++;
    }
    int TT;
    scanf("%d",&TT);
    while (TT--)
    {
        int n,m,Q;
        scanf("%d%d%d",&n,&m,&Q);
        int cnt=0;
        tot=1;
        memset(b,0,sizeof(b));
        for (int k=0;k<=Log[n];k++)
            for (int u=0;u<=Log[m];u++)
                for (int i=1;i<=n;i++)
                {
                    if (i+(1<<k)-1>n)
                        break;;
                    for (int j=1;j<=m;j++)
                    {
                        if (j+(1<<u)-1>m)
                            break;
                        l[i][j][k][u]=++cnt;
                        r[i][j][k][u]=++cnt;
                        if (k>0)
                        {
                            add(l[i][j][k][u],l[i][j][k-1][u],inf);
                            add(l[i][j][k][u],l[i+(1<<k-1)][j][k-1][u],inf);
                            add(r[i][j][k-1][u],r[i][j][k][u],inf);
                            add(r[i+(1<<k-1)][j][k-1][u],r[i][j][k][u],inf);
                        }
                        else if (u>0)
                        {
                            add(l[i][j][k][u],l[i][j][k][u-1],inf);
                            add(l[i][j][k][u],l[i][j+(1<<u-1)][k][u-1],inf);
                            add(r[i][j][k][u-1],r[i][j][k][u],inf);
                            add(r[i][j+(1<<u-1)][k][u-1],r[i][j][k][u],inf);
                        }
                        else
                            add(l[i][j][k][u],r[i][j][k][u],inf);
                    }
                }
        S=++cnt,T=++cnt;
        int ans=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                int x;
                scanf("%d",&x);
                add(r[i][j][0][0],T,x);
                ans+=x;
            }
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                int x;
                scanf("%d",&x);
                add(S,l[i][j][0][0],x);
                ans+=x;
            }
        while (Q--)
        {
            int x1,y1,x2,y2,value,cost;
            scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&value,&cost);
            ans+=cost;
            int u=Log[x2-x1+1],v=Log[y2-y1+1];
            if (value==0)
            {
                add(S,++cnt,cost);
                add(cnt,l[x1][y1][u][v],inf);
                add(cnt,l[x2-(1<<u)+1][y1][u][v],inf);
                add(cnt,l[x1][y2-(1<<v)+1][u][v],inf);
                add(cnt,l[x2-(1<<u)+1][y2-(1<<v)+1][u][v],inf);
            }
            else
            {
                add(++cnt,T,cost);
                add(r[x1][y1][u][v],cnt,inf);
                add(r[x2-(1<<u)+1][y1][u][v],cnt,inf);
                add(r[x1][y2-(1<<v)+1][u][v],cnt,inf);
                add(r[x2-(1<<u)+1][y2-(1<<v)+1][u][v],cnt,inf);
            }
        }
        while (build())
            ans-=dinic(S,inf);
        printf("%d\n",ans);
    }
    return(0);
}

