#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf=1<<30;
int S,T,tot=1,w[30],r[30],c[30][30],b[1000],a[1000000][3];
void add(int x,int y,int c)
{
    a[++tot][0]=y,a[tot][1]=c,a[tot][2]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],b[y]=tot;
}
int q[1000],d[1000];
bool build()
{
    int l,r;
    memset(d,0,sizeof(d));
    q[l=r=1]=S,d[S]=1;
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
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&w[i]);
    for (int i=1;i<=n;i++)
        scanf("%d",&r[i]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            scanf("%d",&c[i][j]);
    w[1]+=r[1];
    bool flag=true;
    for (int i=2;i<=n;i++)
        if (w[i]>w[1])
        {
            flag=false;
            break;
        }
    if (!flag)
        printf("NO\n");
    else
    {
        T=1;
        for (int i=2;i<=n;i++)
            add(S,i,w[1]-w[i]);
        int m=n,ans=0;
        for (int i=2;i<=n;i++)
            for (int j=i+1;j<=n;j++)
            {
                if (!c[i][j])
                    continue;
                m++;
                add(i,m,c[i][j]);
                add(j,m,c[i][j]);
                add(m,T,c[i][j]);
                ans+=c[i][j];
            }
        while (build())
            ans-=dinic(S,inf);
        printf("%s\n",ans?"NO":"YES");
    }
    return(0);
}

