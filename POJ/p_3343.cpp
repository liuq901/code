#include <cstdio>
#include <cstring>
typedef long long ll;
const int N=260;
int n,m,a[N],b[N],c[N],d[N],link[N],e[N][N];
bool vis[N];
inline ll get(int a,int b,ll now)
{
    return(a+b*now);
}
inline bool check(int x,int y,ll now)
{
    if (now<e[x][y])
        return(false);
    return(get(a[x],b[x],0)>=get(c[y],d[y],e[x][y]) || get(a[x],b[x],now-e[x][y])>=get(c[y],d[y],now));
}
bool hungary(int x,ll now)
{
    if (x==0)
        return(true);
    for (int i=1;i<=m;i++)
        if (!vis[i] && check(x,i,now))
        {
            vis[i]=true;
            if (hungary(link[i],now))
            {
                link[i]=x;
                return(true);
            }
        }
    return(false);
}
int main()
{
    while (1)
    {
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%d%d",&a[i],&b[i]);
        for (int i=1;i<=m;i++)
            scanf("%d%d",&c[i],&d[i]);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                scanf("%d",&e[i][j]);
        if (n<m)
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        ll ans=-1,l=0,r=1LL<<40;
        while (l<=r)
        {
            ll mid=l+r>>1;
            int cnt=0;
            memset(link,0,sizeof(link));
            for (int i=1;i<=n;i++)
            {
                memset(vis,0,sizeof(vis));
                if (hungary(i,mid))
                    cnt++;
                if (cnt==m)
                    break;
            }
            if (cnt==m)
                ans=mid,r=mid-1;
            else
                l=mid+1;
        }
        if (ans==-1)
            printf("IMPOSSIBLE\n");
        else
            printf("%I64d\n",ans);
    }
    return(0);
}

