#include <cstdio>
#include <algorithm>
using namespace std;
const int N=200010;
int n,b[N],c[N],e[N],d[N],p[N],log[N],a[N][3],f[20][N];
void dfs(int x,int father,int dep)
{
    e[++e[0]]=x;
    p[x]=e[0];
    d[e[0]]=dep;
    for (int i=b[x];i;i=a[i][2])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        dfs(y,x,dep+1);
        e[++e[0]]=x;
        d[e[0]]=dep;
    }
}
void init()
{
    dfs(1,0,1);
    for (int i=1;i<=e[0];i++)
        f[0][i]=i;
    for (int i=1;i<=log[e[0]];i++)
        for (int j=1;j<=e[0];j++)
        {
            int t=1<<i-1;
            if (j+(1<<i)-1>e[0])
                break;
            f[i][j]=d[f[i-1][j]]<d[f[i-1][j+t]]?f[i-1][j]:f[i-1][j+t];
        }
}
int lcp(int x,int y)
{
    x=p[x],y=p[y];
    if (x>y)
        swap(x,y);
    int t=log[y-x+1],k=1<<t;
    return(d[f[t][x]]<d[f[t][y-k+1]]?e[f[t][x]]:e[f[t][y-k+1]]);
}
int ans[N];
int getans(int x,int father)
{
    int ret=c[x];
    for (int i=b[x];i;i=a[i][2])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        int p=getans(y,x);
        ans[a[i][1]]=p;
        ret+=p;
    }
    return(ret);
}
int main()
{
    scanf("%d",&n);
    log[1]=0;
    for (int i=2;i<=2*n;i++)
    {
        log[i]=log[i-1];
        if (!(i&i-1))
            log[i]++;
    }
    for (int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[i][0]=y,a[i][1]=i,a[i][2]=b[x],b[x]=i;
        a[i+n][0]=x,a[i+n][1]=i,a[i+n][2]=b[y],b[y]=i+n;
    }
    init();
    int Q;
    scanf("%d",&Q);
    while (Q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int t=lcp(x,y);
        c[x]++;
        c[y]++;
        c[t]-=2;
    }
    getans(1,0);
    for (int i=1;i<n;i++)
        printf("%d%c",ans[i],i==n-1?'\n':' ');
    return(0);
}

