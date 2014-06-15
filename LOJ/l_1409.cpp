#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int inf=1<<30;
int S,T,tot,flow,cost,b[160],a[1000000][4];
void add(int x,int y,int z,int c)
{
    a[++tot][0]=y,a[tot][1]=z,a[tot][2]=c,a[tot][3]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=0,a[tot][2]=-c,a[tot][3]=b[y],b[y]=tot;
}
int dd[160],pre[160],pp[160];
bool in[160];
bool spfa()
{
    memset(dd,63,sizeof(dd));
    dd[S]=0;
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
            if (a[i][1] && dd[x]+a[i][2]<dd[y])
            {
                dd[y]=dd[x]+a[i][2];
                pre[y]=x;
                pp[y]=i;
                if (!in[y])
                {
                    in[y]=true;
                    Q.push(y);
                }
            }
        }
    }
    if (dd[T]==dd[0])
        return(false);
    int now=inf;
    for (int i=T;i!=S;i=pre[i])
    {
        int x=pp[i];
        now=min(now,a[x][1]);
    }
    for (int i=T;i!=S;i=pre[i])
    {
        int x=pp[i];
        a[x][1]-=now;
        a[x^1][1]+=now;
    }
    flow+=now;
    cost+=now*dd[T];
    return(true);
}
int r[60],c[60],p[60],d[60],s[60];
int main()
{
    int TT;
    scanf("%d",&TT);
    while (TT--)
    {
        int n,C,R,sum=0;
        scanf("%d%d%d",&n,&C,&R);
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&r[i]);
            sum+=r[i];
        }
        for (int i=1;i<=C;i++)
            scanf("%d%d",&c[i],&p[i]);
        for (int i=1;i<=R;i++)
            scanf("%d%d",&d[i],&s[i]);
        S=C+2*n+1,T=S+1,tot=1;
        memset(b,0,sizeof(b));
        for (int i=1;i<=C;i++)
            add(S,i,c[i],p[i]);
        for (int i=1;i<=n;i++)
        {
            add(i+C,T,r[i],0);
            add(S,i+C+n,r[i],0);
            for (int j=1;j<=C;j++)
                add(j,i+C,inf,0);
            for (int j=1;j<=R;j++)
                if (i+d[j]+1<=n)
                    add(i+C+n,i+d[j]+C+1,inf,s[j]);
            if (i<n)
                add(i+C+n,i+1+C+n,inf,0);
        }
        cost=flow=0;
        while (spfa());
        static int id=0;
        printf("Case %d: ",++id);
        if (flow!=sum)
            printf("impossible\n");
        else
            printf("%d\n",cost);
    }
    return(0);
}

