#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int S,T,tot,b[110],a[10000][4];
void add(int x,int y,int z,int c)
{
    a[++tot][0]=y,a[tot][1]=z,a[tot][2]=c,a[tot][3]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=0,a[tot][2]=-c,a[tot][3]=b[y],b[y]=tot;
}
int cost,flow,d[110],pre[110],p[110];
bool flag[110];
bool spfa()
{
    memset(d,63,sizeof(d));
    queue <int> Q;
    Q.push(S);
    d[S]=0;
    flag[S]=true;
    while (!Q.empty())
    {
        int x=Q.front();
        Q.pop();
        flag[x]=false;
        for (int i=b[x];i;i=a[i][3])
        {
            int y=a[i][0];
            if (a[i][1] && d[x]+a[i][2]<d[y])
            {
                d[y]=d[x]+a[i][2];
                pre[y]=x;
                p[y]=i;
                if (!flag[y])
                {
                    flag[y]=true;
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
int in[60],out[60];
int sqr(int x)
{
    return(x*x);
}
int solve(int n,int K,int G,int value)
{
    memset(b,0,sizeof(b));
    tot=1;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (in[i]<out[j])
                add(i,j+n,1,min(sqr(out[j]-in[i]-K),G)*value);
    S=2*n+1,T=S+1;
    for (int i=1;i<=n;i++)
    {
        add(S,i,1,0);
        add(i+n,T,1,0);
    }
    cost=flow=0;
    while (spfa());
    if (flow!=n)
        return(-1);
    return(cost);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,K,G;
        scanf("%d%d%d",&n,&K,&G);
        for (int i=1;i<=n;i++)
            scanf("%d",&in[i]);
        for (int i=1;i<=n;i++)
            scanf("%d",&out[i]);
        static int id=0;
        printf("Case %d: ",++id);
        int ans=solve(n,K,G,1);
        if (ans==-1)
            printf("impossible\n");
        else
            printf("%d %d\n",ans,-solve(n,K,G,-1));
    }
    return(0);
}

