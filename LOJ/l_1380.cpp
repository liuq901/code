#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,root,ans,tot,len[1010],pre[1010],b[1010],rb[1010],a[1000000][3],ra[1000000][2];
bool visit[1010],circle[1010];
void add(int x,int y,int z)
{
    a[++tot][0]=y,a[tot][1]=z,a[tot][2]=b[x],b[x]=tot;
    ra[tot][0]=x,ra[tot][1]=rb[y],rb[y]=tot;
}
void dfs(int t)
{
    visit[t]=true;
    for (int k=b[t];k;k=a[k][2])
    {
        int i=a[k][0];
        if (!visit[i])
            dfs(i);
    }
}
bool check()
{
    memset(visit,0,sizeof(visit));
    dfs(root);
    for (int i=1;i<=n;i++)
        if (!visit[i])
            return(false);
    return(true);
}
int exist_circle()
{
    pre[root]=root;
    for (int i=1;i<=n;i++)
        if (!circle[i] && i!=root)
        {
            pre[i]=i;
            len[i]=1<<30;
            for (int k=rb[i];k;k=ra[k][1])
            {
                int j=ra[k][0];
                if (!circle[j] && a[k][1]<len[i])
                {
                    pre[i]=j;
                    len[i]=a[k][1];
                }
            }
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
    ans+=len[t];
    for (int i=pre[t];i!=t;i=pre[i])
    {
        ans+=len[i];
        circle[i]=true;
    }
    for (int k=rb[t];k;k=ra[k][1])
    {
        int i=ra[k][0];
        if (!circle[i])
            a[k][1]-=len[t];
    }
    for (int j=pre[t];j!=t;j=pre[j])
    {
        for (int k=rb[j];k;k=ra[k][1])
        {
            int i=ra[k][0];
            if (circle[i] || i==t)
                continue;
            add(i,t,a[k][1]-len[j]);
        }
        for (int k=b[j];k;k=a[k][2])
        {
            int i=a[k][0];
            if (circle[i] || i==t)
                continue;
            add(t,i,a[k][1]);
        }
    }
}
void solve()
{
    memset(circle,0,sizeof(circle));
    int j;
    while ((j=exist_circle())!=-1)
        update(j);
    for (int j=1;j<=n;j++)
        if (j!=root && !circle[j])
            ans+=len[j];
    printf("%d\n",ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d%d",&n,&m,&root);
        root++;
        memset(b,0,sizeof(b));
        memset(rb,0,sizeof(rb));
        tot=0;
        for (int i=1;i<=m;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            a++,b++;
            add(a,b,c);
        }
        ans=0;
        static int id=0;
        printf("Case %d: ",++id);
        if (!check())
            printf("impossible\n");
        else
            solve();
    }
    return(0);
}

