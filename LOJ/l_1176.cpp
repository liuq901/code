#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;
map <string,int> M;
void init()
{
    M["XXL"]=1;
    M["XL"]=2;
    M["L"]=3;
    M["M"]=4;
    M["S"]=5;
    M["XS"]=6;
}
int tot,S,T,b[110],a[10010][3];
void add(int x,int y,int z)
{
    a[++tot][0]=y,a[tot][1]=z,a[tot][2]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],b[y]=tot;
}
int d[110],q[110];
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
    init();
    int TT;
    scanf("%d",&TT);
    while (TT--)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        memset(b,0,sizeof(b));
        tot=1,S=n+7,T=S+1;
        for (int i=1;i<=n;i++)
        {
            char a[10],b[10];
            scanf("%s%s",a,b);
            add(S,i,1);
            add(i,M[a]+n,1);
            add(i,M[b]+n,1);
        }
        for (int i=1;i<=6;i++)
            add(i+n,T,m);
        int ans=0;
        while (build())
            ans+=dinic(S,1<<30);
        static int id=0;
        printf("Case %d: %s\n",++id,ans==n?"YES":"NO");
    }
    return(0);
}

