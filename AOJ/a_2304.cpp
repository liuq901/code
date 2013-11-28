#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int inf=1<<30;
int S,T,tot,b[310],a[2010][3];
vector <int> e;
void add(int x,int y)
{
    a[++tot][0]=y,a[tot][1]=1,a[tot][2]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=1,a[tot][2]=b[y],b[y]=tot;
}
int d[310],q[310];
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
            return(flow);
    }
    if (k==flow)
        d[x]=-1;
    return(flow-k);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    tot=1;
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
    }
    scanf("%d%d",&S,&T);
    int ans=0;
    while (build())
        ans+=dinic(S,inf);
    printf("%d\n",ans);
    for (int i=2;i<=tot;i+=2)
        if (a[i][1]>1)
            e.push_back(i/2);
    printf("%d\n",e.size());
    for (int i=0;i<e.size();i++)
        printf("%d\n",e[i]);
    return(0);
}

