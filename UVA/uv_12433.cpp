#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int inf=1000000000;
int ans,tot,S,T,b[210],a[1000000][4];
void add(int x,int y,int v,int c)
{
    a[++tot][0]=y,a[tot][1]=v,a[tot][2]=c,a[tot][3]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=0,a[tot][2]=-c,a[tot][3]=b[y],b[y]=tot;
}
int d[210],p[210],pre[210];
bool in[210];
queue <int> Q;
bool spfa()
{
    for (int i=S;i<=T;i++)
        d[i]=2*inf;
    in[S]=true;
    d[S]=0;
    Q.push(S);
    while (!Q.empty())
    {
        int x=Q.front();
        Q.pop();
        in[x]=false;
        for (int i=b[x];i;i=a[i][3])
        {
            int y=a[i][0];
            if (a[i][1]!=0 && d[x]+a[i][2]<d[y])
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
    if (d[T]==2*inf)
        return(false);
    if (d[T]>=inf)
    {
        ans=-1;
        return(false);
    }
    int flow=inf;
    for (int i=T;i!=S;i=pre[i])
    {
        int x=p[i];
        flow=min(flow,a[x][1]);
    }
    ans+=flow*d[T];
    for (int i=T;i!=S;i=pre[i])
    {
        int x=p[i];
        a[x][1]-=flow;
        a[x^1][1]+=flow;
    }
    return(true);
}
int main()
{
    int test;
    scanf("%d",&test);
    while (test--)
    {
        int n,C,R;
        scanf("%d%d%d",&n,&C,&R);
        S=0,T=3*n+1,tot=1;
        memset(b,0,sizeof(b));
        for (int i=1;i<=n;i++)
        {
            int r;
            scanf("%d",&r);
            add(i,i+n,r,0);
            add(i+n,T,inf,0);
            add(S,i+2*n,r,0);
            if (i>1)
                add(i-1,i,inf,0);
        }
        for (int i=1;i<=C;i++)
        {
            int c,p;
            scanf("%d%d",&c,&p);
            add(S,1,c,p);
        }
        add(S,1,inf,inf);
        for (int i=1;i<=R;i++)
        {
            int d,s;
            scanf("%d%d",&d,&s);
            for (int j=1;j<=n;j++)
            {
                if (j+d+1>n)
                    break;
                add(j+2*n,j+d+1,inf,s);
            }
        }
        ans=0;
        while (spfa());
        static int id=0;
        printf("Case %d: ",++id);
        if (ans==-1)
            printf("impossible\n");
        else
            printf("%d\n",ans);
    }
    return(0);
}

