#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
struct data
{
    int l,r,u,d,y;
};
data a[100000];
char buf[20][20];
int n,m,ans,sum[100],p[100];
vector <pair <int,int> > b;
inline bool check(int x,int y,int u,int v)
{
    return(x==u || y==v || x+y==u+v || x-y==u-v);
}
void build()
{
    int N=b.size();
    for (int i=1;i<=N;i++)
        a[i].l=i-1,a[i].r=i+1,sum[i]=0,p[i]=i;
    a[0].l=N,a[N].r=0;
    a[0].r=min(1,N);
    int tot=N;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            int prev=tot+1;
            for (int k=0;k<b.size();k++)
            {
                if (!check(i,j,b[k].first,b[k].second))
                    continue;
                tot++;
                a[tot].l=tot-1;
                a[tot].r=tot+1;
                a[tot].u=p[k+1];
                a[p[k+1]].d=tot;
                p[k+1]=tot;
                a[tot].y=k+1;
                sum[k+1]++;
            }
            if (tot>=prev)
                a[tot].r=prev,a[prev].l=tot;
        }
    for (int i=1;i<=N;i++)
        a[p[i]].d=i,a[i].u=p[i];
}
bool vis[100];
int best()
{
    memset(vis,0,sizeof(vis));
    int ans=0;
    for (int i=a[0].r;i;i=a[i].r)
    {
        if (vis[i])
            continue;
        ans++;
        for (int j=a[i].d;j!=i;j=a[j].d)
            for (int k=a[j].r;k!=j;k=a[k].r)
                vis[a[k].y]=true;
    }
    return(ans);
}
void del(int x)
{
    for (int i=a[x].d;i!=x;i=a[i].d)
    {
        sum[a[i].y]--;
        a[a[i].l].r=a[i].r;
        a[a[i].r].l=a[i].l;
    }
}
void renew(int x)
{
    for (int i=a[x].u;i!=x;i=a[i].u)
    {
        sum[a[i].y]++;
        a[a[i].l].r=i;
        a[a[i].r].l=i;
    }
}
bool DLX(int dep)
{
    if (a[0].r==0)
        return(true);
    if (dep+best()>ans)
        return(false);
    int k,mi=1<<30;
    for (int i=a[0].r;i;i=a[i].r)
        if (sum[i]<mi)
            mi=sum[k=i];
    for (int i=a[k].d;i!=k;i=a[i].d)
    {
        del(i);
        for (int j=a[i].r;j!=i;j=a[j].r)
            del(j);
        if (DLX(dep+1))
            return(true);
        for (int j=a[i].l;j!=i;j=a[j].l)
            renew(j);
        renew(i);
    }
    return(false);
}
int main()
{
    while (scanf("%d%d",&n,&m)==2)
    {
        for (int i=1;i<=n;i++)
            scanf("%s",buf[i]+1);
        b.clear();
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                if (buf[i][j]=='X')
                    b.push_back(make_pair(i,j));
        ans=0;
        int limit=min(min(n,m),5);
        while (ans<limit)
        {
            build();
            if (DLX(0))
                break;
            ans++;
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

