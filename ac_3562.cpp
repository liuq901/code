#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
const int inf=1<<30;
int tot,n,m,S,T,P[200],I[200],b[200],a[1000000][3];
double cost,value[200][200],c[1000000];
void add(int x,int y,int capa,double v)
{
    a[++tot][0]=y,a[tot][1]=capa,a[tot][2]=b[x],c[tot]=v,b[x]=tot;
    a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],c[tot]=-v,b[y]=tot;
}
double d[200];
bool in[200];
queue <int> Q;
int pre[200],p[200];
bool spfa()
{
    for (int i=S;i<=T;i++)
        d[i]=1e10;
    d[S]=0;
    Q.push(S);
    in[S]=true;
    while (!Q.empty())
    {
        int x=Q.front();
        Q.pop();
        in[x]=false;
        for (int i=b[x];i;i=a[i][2])
        {
            int y=a[i][0];
            if (a[i][1] && d[x]+c[i]-d[y]<-1e-8)
            {
                d[y]=d[x]+c[i];
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
    if (d[T]>1e9)
        return(false);
    int flow=inf;
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
    cost+=flow*d[T];
    return(true);
}
double netflow(int flag)
{
    S=0,T=n+m+1,tot=1;
    memset(b,0,sizeof(b));
    for (int i=1;i<=n;i++)
        add(S,i,P[i],0);
    for (int i=1;i<=m;i++)
        add(i+n,T,I[i],0);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            if (value[i][j]<0)
                continue;
            add(i,j+n,inf,value[i][j]*flag);
        }
    cost=0;
    while (spfa());
    return(cost);
}
int main()
{
    while (1)
    {
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%d",&P[i]);
        for (int i=1;i<=m;i++)
            scanf("%d",&I[i]);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                scanf("%lf",&value[i][j]);
        static int id=0;
        printf("Problem %d: %.2f to %.2f\n",++id,netflow(1),fabs(netflow(-1)));
    }
    return(0);
}

