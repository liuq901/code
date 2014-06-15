#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int tot,b[60],a[1000000][4];
void add(int x,int y,int z,int c)
{
    a[++tot][0]=y,a[tot][1]=z,a[tot][2]=c,a[tot][3]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=0,a[tot][2]=-c,a[tot][3]=b[y],b[y]=tot;
}
int S,T,flow,cost,d[60],pre[60],p[60];
bool in[60];
bool spfa()
{
    memset(d,63,sizeof(d));
    d[S]=0;
    in[S]=true;
    queue <int> Q;
    Q.push(S);
    while (!Q.empty())
    {
        int x=Q.front();
        Q.pop();
        in[x]=false;
        for (int i=b[x];i;i=a[i][3])
        {
            int y=a[i][0];
            if (a[i][1] && d[x]+a[i][2]<d[y])
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
    int now=flow;
    for (int i=T;i!=S;i=pre[i])
    {
        int x=p[i];
        now=min(now,a[x][1]);
    }
    for (int i=T;i!=S;i=pre[i])
    {
        int x=p[i];
        a[x][1]-=now;
        a[x^1][1]+=now;
    }
    flow-=now;
    cost+=d[T]*now;
    return(flow>0);
}
int main()
{
    int TT;
    scanf("%d",&TT);
    while (TT--)
    {
        int n,m;
        scanf("%d%d%d",&n,&m,&flow);
        memset(b,0,sizeof(b));
        S=1,T=n,tot=1;
        for (int i=1;i<=m;i++)
        {
            int x,y,w,c;
            scanf("%d%d%d%d",&x,&y,&w,&c);
            add(x,y,w,c);
            add(y,x,w,c);
        }
        cost=0;
        while (spfa());
        static int id=0;
        printf("Case %d: ",++id);
        if (flow)
            printf("impossible\n");
        else
            printf("%d\n",cost);
    }
    return(0);
}

