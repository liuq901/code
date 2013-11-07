#include <cstdio>
#include <cstring>
#include <queue>
#include <numeric>
using namespace std;
int cost,flow,tot,S,T,v[20],b[50],a[1000000][4];
void add(int x,int y,int v,int c)
{
    a[++tot][0]=y,a[tot][1]=v,a[tot][2]=c,a[tot][3]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=0,a[tot][2]=-c,a[tot][3]=b[y],b[y]=tot;
}
int d[50],pre[50],p[50];
bool in[50];
bool spfa()
{
    queue <int> Q;
    memset(d,-63,sizeof(d));
    Q.push(S);
    d[S]=0;
    in[S]=true;
    while (!Q.empty())
    {
        int x=Q.front();
        in[x]=false;
        Q.pop();
        for (int i=b[x];i;i=a[i][3])
        {
            int y=a[i][0];
            if (a[i][1] && d[x]+a[i][2]>d[y])
            {
                d[y]=d[x]+a[i][2];
                pre[y]=x;
                p[y]=i;
                if (!in[y])
                {
                    in[y]=true;
                    Q.push(y);
                }
            }
        }
    }
    if (d[T]==d[0])
        return(false);
    flow++;
    cost+=d[T];
    for (int i=T;i!=S;i=pre[i])
    {
        int x=p[i];
        a[x][1]--;
        a[x^1][1]++;
    }
    return(true);
}
int pp[110][110];
int main()
{
    int Q;
    scanf("%d",&Q);
    while (Q--)
    {
        int n,m,K;
        scanf("%d%d%d",&n,&m,&K);
        S=n+m+1,T=S+1;
        for (int i=1;i<=m;i++)
            scanf("%d",&v[i]);
        memset(b,0,sizeof(b));
        tot=1;
        for (int i=1;i<=n;i++)
            add(i+m,T,1,0);
        for (int i=1;i<=m;i++)
            for (int j=1;j<=n;j++)
                scanf("%d",&pp[i][j]);
        for (int i=1;i<=m;i++)
            for (int j=1;j<=n;j++)
                if (pp[i][j])
                    add(i,j+m,1,0);
        for (int i=1;i<=m;i++)
        {
            add(S,i,v[i]/K,K);
            if (v[i]%K>1)
                add(S,i,1,v[i]%K);
        }
        cost=flow=0;
        while (spfa());
        static int id=0;
        printf("Case #%d: %s\n",++id,accumulate(v+1,v+m+1,0)<=cost+n-flow?"YES":"NO");
    }
    return(0);
}

