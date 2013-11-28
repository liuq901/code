#pragma comment(linker,"/STACK:16777216")
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=100010,inf=1<<30;
int S,T,tot,X[N],b[N],a[N*2][3];
void add(int x,int y,int c)
{
    a[++tot][0]=y,a[tot][1]=c,a[tot][2]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=c,a[tot][2]=b[y],b[y]=tot;
}
int q[N],d[N];
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
    int test;
    scanf("%d",&test);
    while (test--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            scanf("%d%*d",&X[i]);
        S=T=1;
        for (int i=1;i<=n;i++)
        {
            if (X[i]<X[S])
                S=i;
            if (X[i]>X[T])
                T=i;
        }
        tot=1;
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            add(x,y,z);
        }
        int ans=0;
        while (build())
            ans+=dinic(S,inf);
        printf("%d\n",ans);
    }
    return(0);
}

