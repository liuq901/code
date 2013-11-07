#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int S,T,tot=1,n,tt,inf,b[1000],q[1000000],a[1000000][3],dep[20][20],dis[20][20],p[20][20],s[20][20];
char ma[20][20],mb[20][20];
void add(int x,int y,int c)
{
    a[++tot][0]=y,a[tot][1]=c,a[tot][2]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],b[y]=tot;
}
void bfs(int x0,int y0,bool flag)
{
    int l,r,id=p[x0][y0];
    q[l=r=1]=x0*1000+y0;
    memset(dis,63,sizeof(dis));
    inf=dis[0][0];
    dis[x0][y0]=0;
    while (l<=r)
    {
        int x0=q[l]/1000,y0=q[l++]%1000;
        if (flag && s[x0][y0]!=0 && dis[x0][y0]<=tt && dis[x0][y0]<=dep[x0][y0])
            add(id,s[x0][y0],inf);
        if (dis[x0][y0]>tt || dis[x0][y0]>=dep[x0][y0])
            continue;
        if (id==3 && s[x0][y0]==9)
            printf("%d\n",dis[x0][y0]);
        for (int i=0;i<4;i++)
        {
            int x=x0+c[i][0],y=y0+c[i][1];
            if (x>0 && x<=n && y>0 && y<=n && isdigit(ma[x][y]) && dis[x][y]==inf)
            {
                dis[x][y]=dis[x0][y0]+1;
                q[++r]=x*1000+y;
            }
        }
    }
}
int d[1000];
bool build()
{
    memset(d,0,sizeof(d));
    int l,r;
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
        if (k==0)
            return(flow);
    }
    if (k==flow)
        d[x]=-1;
    return(flow-k);
}
int main()
{
    scanf("%d%d",&n,&tt);
    for (int i=1;i<=n;i++)
        scanf("%s",ma[i]+1);
    for (int i=1;i<=n;i++)
        scanf("%s",mb[i]+1);
    memset(dep,63,sizeof(dep));
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (ma[i][j]=='Z')
                bfs(i,j,false);
    memcpy(dep,dis,sizeof(dis));
    int t=1;
    S=0,T=1;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            if (ma[i][j]>'0' && ma[i][j]<='9')
            {
                p[i][j]=++t;
                add(S,t,ma[i][j]-'0');
            }
            if (mb[i][j]>'0' && mb[i][j]<='9')
            {
                s[i][j]=++t;
                add(t,T,mb[i][j]-'0');
            }
        }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (p[i][j])
                bfs(i,j,true);
    int ans=0;
    while (build())
        ans+=dinic(S,inf);
    printf("%d\n",ans);
    return(0);
}

