#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf=1<<30;
int S,T,tot,b[1510],d[1510],c[300010],a[600010][3];
void add(int x,int y,int c)
{
    a[++tot][0]=y,a[tot][1]=c,a[tot][2]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],b[y]=tot;
}
int q[1510],f[1510];
bool vis[1510];
void bfs()
{
    memset(f,0,sizeof(f));
    memset(vis,0,sizeof(vis));
    int l,r;
    q[l=r=1]=S;
    f[S]=inf,vis[S]=true;
    while (l<=r)
    {
        int x=q[l++];
        for (int i=b[x];i;i=a[i][2])
        {
            int y=a[i][0];
            if (d[y]!=d[x]+1)
                continue;
            int t=min(f[x],a[i][1]);
            f[x]-=t;
            f[y]+=t;
            a[i][1]-=t;
            if (!vis[y])
            {
                q[++r]=y;
                vis[y]=true;
            }
            if (f[x]==0)
                break;
        }
    }
    for (int i=r-1;i>1;i--)
    {
        int x=q[i];
        for (int i=b[x];i;i=a[i][2])
        {
            int y=a[i][0];
            if (d[y]+1!=d[x])
                continue;
            int t=min(f[x],c[i/2]-a[i^1][1]);
            f[x]-=t;
            f[y]+=t;
            a[i^1][1]+=t;
            if (f[x]==0)
                break;
        }
    }
}
int dinic(int x,int flow)
{
    if (x==T)
        return(flow);
    int k=flow;
    for (int i=b[x];i;i=a[i][2])
    {
        int y=a[i][0];
        if (d[y]!=d[x]+1 || !a[i][1] || i&1)
            continue;
        int t=dinic(y,min(k,a[i][1]));
        k-=t;
        a[i][1]-=t;
        if (k==t)
            return(flow);
    }
    if (k==flow)
        d[x]=-1;
    return(flow-k);
}
void main2()
{
    int n,m,L;
    scanf("%d%d%d",&n,&m,&L);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&d[i]);
        if (d[i]==1)
            S=i;
        else if (d[i]==L)
            T=i;
    }
    memset(b,0,sizeof(b));
    tot=1;
    for (int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
        c[i]=z;
    }
    bfs();
    while (1)
    {
        int t=dinic(S,inf);
        if (t==0)
            break;
    }
    for (int i=2;i<=tot;i+=2)
        printf("%d\n",c[i/2]-a[i][1]);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
        main2();
    return(0);
}

