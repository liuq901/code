#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const double inf=1e26;
int n,m,root,pre[110];
double ans,graph[110][110],v[110][110];
bool visit[110],circle[110];
inline double sqr(double x)
{
    return(x*x);
}
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
double dist(int x,int y)
{
    double a,b,ab;
    a=b=ab=0;
    for (int i=1;i<=m;i++)
    {
        a+=sqr(v[x][i]);
        b+=sqr(v[y][i]);
        ab+=v[x][i]*v[y][i];
    }
    if (sign(a)==0)
        return(b);
    return((a*b-sqr(ab))/a);
}
int exist_circle()
{
    root=1;
    pre[root]=root;
    for (int i=1;i<=n;i++)
        if (!circle[i] && i!=root)
        {
            pre[i]=i;
            graph[i][i]=inf;
            for (int j=1;j<=n;j++)
                if (!circle[j] && graph[j][i]<graph[pre[i]][i])
                    pre[i]=j;
        }
    for (int i=1;i<=n;i++)
    {
        if (circle[i])
            continue;
        memset(visit,0,sizeof(visit));
        int j=i;
        while (!visit[j])
        {
            visit[j]=true;
            j=pre[j];
        }
        if (j==root)
            continue;
        return(j);
    }
    return(-1);
}
void update(int t)
{
    ans+=graph[pre[t]][t];
    for (int i=pre[t];i!=t;i=pre[i])
    {
        ans+=graph[pre[i]][i];
        circle[i]=true;
    }
    for (int i=1;i<=n;i++)
        if (!circle[i] && graph[i][t]<inf)
            graph[i][t]-=graph[pre[t]][t];
    for (int j=pre[t];j!=t;j=pre[j])
        for (int i=1;i<=n;i++)
        {
            if (circle[i])
                continue;
            if (graph[i][j]<inf)
                graph[i][t]=min(graph[i][t],graph[i][j]-graph[pre[j]][j]);
            graph[t][i]=min(graph[j][i],graph[t][i]);
        }
}
void solve()
{
    int j;
    memset(circle,0,sizeof(circle));
    while ((j=exist_circle())!=-1)
        update(j);
    for (j=1;j<=n;j++)
        if (j!=root && !circle[j])
            ans+=graph[pre[j]][j];
}
int main()
{
    scanf("%d%d",&m,&n);
    n++;
    for (int i=2;i<=n;i++)
        for (int j=1;j<=m;j++)
            scanf("%lf",&v[i][j]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (i!=j)
                graph[i][j]=dist(i,j);
            else
                graph[i][j]=inf;
    root=1;
    ans=0;
    solve();
    printf("%.15f\n",ans);
    return(0);
}

