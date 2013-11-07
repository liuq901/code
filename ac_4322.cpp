#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf=1<<30;
int tot,S,T,b[110],a[100000][3],f[60][60];
void add(int x,int y,int c)
{
    a[++tot][0]=y,a[tot][1]=c,a[tot][2]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],b[y]=tot;
}
int d[110],q[110];
bool build()
{
    int l,r;
    memset(d,0,sizeof(d));
    q[l=r=1]=S;
    d[S]=1;
    while (l<=r)
    {
        int x=q[l++];
        for (int i=b[x];i;i=a[i][2])
        {
            int y=a[i][0];
            if (!a[i][1] || d[y])
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
        if (!a[i][1] || d[y]!=d[x]+1)
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
    while (1)
    {
        int n,m,K;
        scanf("%d%d%d",&n,&m,&K);
        if (n==0 && m==0 && K==0)
            break;
        memset(f,63,sizeof(f));
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            f[x][y]=1;
        }
        for (int i=1;i<=n;i++)
            f[i][i]=0;
        for (int k=1;k<=n;k++)
            for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++)
                    f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
        memset(b,0,sizeof(b));
        tot=1;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if (f[i][j]==1 && f[1][i]+f[j][n]+1<=K)
                    add(i+n,j,inf);
        for (int i=1;i<=n;i++)
            add(i,i+n,1);
        S=n+1,T=n;
        int ans=0;
        while (build())
            ans+=dinic(S,inf);
        printf("%d\n",ans);
    }
    return(0);
}

