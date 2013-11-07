#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf=2100000000;
int tot,S,T,b[410],a[100000][3];
void add(int x,int y,int z)
{
    a[++tot][0]=y,a[tot][1]=z,a[tot][2]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],b[y]=tot;
}
int d[410],q[410];
bool build()
{
    memset(d,0,sizeof(d));
    int l,r;
    q[l=r=1]=S;
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
        if (!k)
            break;
    }
    if (k==flow)
        d[x]=-1;
    return(flow-k);
}
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)==2)
    {
        scanf("%d%d",&S,&T);
        T=T+n;
        memset(b,0,sizeof(b));
        tot=1;
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            add(i,i+n,x);
        }
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            add(x+n,y,inf);
            add(y+n,x,inf);
        }
        int ans=0;
        while (build())
            ans+=dinic(S,inf);
        printf("%d\n",ans);
    }
    return(0);
}

