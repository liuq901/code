#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll inf=1LL<<50;
int tot,b[110],a[10000][3];
ll ans,c[10000];
void add(int x,int y,int v,ll C)
{
    a[++tot][0]=y,a[tot][1]=v,a[tot][2]=b[x],c[tot]=C,b[x]=tot;
    a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],c[tot]=-C,b[y]=tot;
}
bool in[110],f[110];
ll d[110];
int pre[110],p[110],vis[110],g[110],q[1010];
void work(int x)
{
    memset(f,0,sizeof(f));
    int k;
    for (int i=x;;i=pre[i])
    {
        if (f[i])
        {
            k=i;
            break;
        }
        f[i]=true;
    }
    for (int i=pre[k];i!=k;i=pre[i])
    {
        x=p[i];
        ans+=c[x];
        a[x][1]--;
        a[x^1][1]++;
    }
    x=p[k];
    ans+=c[x];
    a[x][1]--;
    a[x^1][1]++;
}
bool spfa(int n)
{
    memset(vis,0,sizeof(vis));
    memset(d,0,sizeof(d));
    int l=0,r=0;
    for (int i=1;i<=n;i++)
    {
        q[++r]=i;
        in[i]=true;
        g[i]=0;
    }
    while (l!=r)
    {
        l=l==1000?1:l+1;
        int x=q[l];
        in[x]=false;
        if (g[x]>=n)
        {
            work(x);
            return(true);
        }
        for (int i=b[x];i;i=a[i][2])
        {
            int y=a[i][0];
            if (a[i][1] && d[x]+c[i]<d[y])
            {
                d[y]=d[x]+c[i];
                g[y]=g[x]+1;
                pre[y]=x;
                p[y]=i;
                if (!in[y])
                {
                    in[y]=true;
                    r=r==1000?1:r+1;
                    q[r]=y;
                    int k=l==1000?1:l+1;
                    if (d[q[r]]<d[q[k]])
                        swap(q[r],q[k]);
                }
            }
        }
    }
    return(false);
}
int main()
{
    int test;
    scanf("%d",&test);
    while (test--)
    {
        int n,m,S,T;
        scanf("%d%d%d%d",&n,&m,&S,&T);
        ans=0;
        memset(b,0,sizeof(b));
        tot=1;
        for (int i=1;i<=m;i++)
        {
            int x,y,remove,insert;
            scanf("%d%d%d%d",&x,&y,&insert,&remove);
            ans+=remove;
            add(x,y,1,insert-remove);
        }
        add(T,S,1,-inf);
        ans+=inf;
        while (spfa(n));
        static int id=0;
        printf("Case %d: ",++id);
        if (ans>=inf/2)
            printf("impossible\n");
        else
            printf("%I64d\n",ans);
    }
    return(0);
}

