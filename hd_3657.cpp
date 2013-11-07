#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf=1<<30;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool ok[60][60];
int S,T,tot,b[2510],a[100000][3],v[60][60],id[60][60];
void add(int x,int y,int z)
{
    a[++tot][0]=y,a[tot][1]=z,a[tot][2]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],b[y]=tot;
}
int d[2510],q[2510];
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
    int n,m,K;
    while (scanf("%d%d%d",&n,&m,&K)==3)
    {
        int tmp=0,ans=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                scanf("%d",&v[i][j]);
                ans+=v[i][j];
                id[i][j]=++tmp;
            }
        memset(ok,0,sizeof(ok));
        for (int i=1;i<=K;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            ok[x][y]=true;
        }
        memset(b,0,sizeof(b));
        tot=1;
        S=n*m+1,T=S+1;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                bool flag=i+j&1;
                for (int k=0;k<4;k++)
                {
                    int x=i+c[k][0],y=j+c[k][1];
                    if (x<=0 || x>n || y<=0 || y>m)
                        continue;
                    if (flag)
                        add(id[i][j],id[x][y],2*(v[i][j]&v[x][y]));
                }
                int value=ok[i][j]?inf:v[i][j];
                if (flag)
                    add(S,id[i][j],value);
                else
                    add(id[i][j],T,value);
            }
        while (build())
            ans-=dinic(S,inf);
        printf("%d\n",ans);
    }
    return(0);
}

