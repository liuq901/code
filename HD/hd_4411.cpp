#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll inf=10000000000000LL;
int S,T,tot,b[210],a[1000000][3],c[110][110];
ll ans,cost[1000000];
void add(int x,int y,int z,ll c)
{
    a[++tot][0]=y,a[tot][1]=z,a[tot][2]=b[x],cost[tot]=c,b[x]=tot;
    a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],cost[tot]=-c,b[y]=tot;
}
ll d[210];
int q[210],pre[210],p[210];
bool in[210];
bool SPFA()
{
    memset(d,63,sizeof(d));
    ll inf=d[0];
    int l=0,r=1;
    q[1]=S;
    in[S]=true;
    d[S]=0;
    while (l!=r)
    {
        int x=q[l=l==205?1:l+1];
        in[x]=false;
        for (int i=b[x];i;i=a[i][2])
        {
            int y=a[i][0];
            if (a[i][1] && d[x]+cost[i]<d[y])
            {
                d[y]=d[x]+cost[i];
                pre[y]=x;
                p[y]=i;
                if (!in[y])
                {
                    in[y]=true;
                    q[r=r==205?1:r+1]=y;
                }
            }
        }
    }
    if (d[T]==inf)
        return(false);
    int flow=1<<30;
    for (int i=T;i!=S;i=pre[i])
    {
        int x=p[i];
        flow=min(flow,a[x][1]);
    }
    for (int i=T;i!=S;i=pre[i])
    {
        int x=p[i];
        a[x][1]-=flow;
        a[x^1][1]+=flow;
    }
    ans+=d[T]*flow;
    return(true);
}
int main()
{
    while (1)
    {
        int n,m,K;
        scanf("%d%d%d",&n,&m,&K);
        if (n==0 && m==0 && K==0)
            break;
        memset(c,63,sizeof(c));
        for (int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            c[x][y]=min(c[x][y],z);
            c[y][x]=min(c[y][x],z);
        }
        for (int i=0;i<=n;i++)
            c[i][i]=0;
        for (int k=0;k<=n;k++)
            for (int i=0;i<=n;i++)
                for (int j=0;j<=n;j++)
                    c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
        S=2*n+2,T=2*n+1,tot=1;
        memset(b,0,sizeof(b));
        add(S,0,K,0);
        add(0,T,K,0);
        for (int i=1;i<=n;i++)
        {
            add(i,i+n,1,-inf);
            add(0,i,K,c[0][i]);
            add(i+n,T,K,c[i][0]);
        }
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
                add(i+n,j,K,c[i][j]);
        ans=0;
        while (SPFA());
        printf("%d\n",int(ans+inf*n));
    }
    return(0);
}

