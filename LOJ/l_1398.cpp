#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int S,T,tot,b[210],a[1000000][3];
void add(int x,int y)
{
    a[++tot][0]=y,a[tot][1]=1,a[tot][2]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],b[y]=tot;
}
int d[210],q[210];
bool build()
{
    memset(d,0,sizeof(d));
    d[S]=1;
    int l,r;
    q[l=r=1]=S;
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
int X[110],Y[110];
int sqr(int x)
{
    return(x*x);
}
int main()
{
    int TT;
    scanf("%d",&TT);
    while (TT--)
    {
        int H,n,D;
        scanf("%*d%d%d%d",&H,&n,&D);
        for (int i=1;i<=n;i++)
            scanf("%d%d",&X[i],&Y[i]);
        S=2*n+1,T=S+1,tot=1;
        memset(b,0,sizeof(b));
        for (int i=1;i<=n;i++)
        {
            if (Y[i]<=D)
                add(S,i);
            if (Y[i]>=H-D)
                add(i+n,T);
            add(i,i+n);
            for (int j=i+1;j<=n;j++)
                if (sqr(X[i]-X[j])+sqr(Y[i]-Y[j])<=sqr(2*D))
                {
                    add(i+n,j);
                    add(j+n,i);
                }
        }
        int ans=0;
        while (build())
            ans+=dinic(S,1<<30);
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

