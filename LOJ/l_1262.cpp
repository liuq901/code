#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int tot,S,T,b[210],a[1000000][3];
void add(int x,int y,int z)
{
    a[++tot][0]=y,a[tot][1]=z,a[tot][2]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],b[y]=tot;
}
int d[210],q[210];
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
int u[110],v[110],edge[60][60];
int main()
{
    int TT;
    scanf("%d",&TT);
    while (TT--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n+m-1;i++)
            scanf("%d",&u[i]);
        for (int i=1;i<=n+m-1;i++)
            scanf("%d",&v[i]);
        memset(b,0,sizeof(b));
        tot=1,S=n+m,T=2*S;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                int x=i+j-1,y=i-j+m;
                u[x]--,v[y]--;
                edge[i][j]=tot+1;
                add(x,y+n+m,99);
            }
        for (int i=1;i<=n+m-1;i++)
        {
            add(S,i,u[i]);
            add(i+n+m,T,v[i]);
        }
        while (build())
            dinic(S,1<<30);
        static int id=0;
        printf("Case %d:\n",++id);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                int x=edge[i][j];
                printf("%d%c",a[x^1][1]+1,j==m?'\n':' ');
            }
    }
    return(0);
}

