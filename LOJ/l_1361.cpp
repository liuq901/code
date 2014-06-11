#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf=1<<30;
int S,T,tot,b[210],a[1000000][3];
void add(int x,int y,int c1,int c2)
{
    a[++tot][0]=y,a[tot][1]=c1,a[tot][2]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=c2,a[tot][2]=b[y],b[y]=tot;
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
int up[210],down[210];
int main()
{
    int TT;
    scanf("%d",&TT);
    while (TT--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            scanf("%d",&up[i]);
        for (int i=1;i<=n;i++)
            scanf("%d",&down[i]);
        memset(b,0,sizeof(b));
        S=n+1,T=S+1,tot=1;
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            if (x==-1)
                up[i]=inf;
            else if (x==1)
                down[i]=inf;
            add(S,i,up[i],0);
            add(i,T,down[i],0);
        }
        for (int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            add(x,y,z,z);
        }
        int ans=0;
        while (build())
            ans+=dinic(S,inf);
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

