#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int limit=8;
int p[limit],q[limit],g[1<<limit],cnt[1<<limit],a[10010],b[10010],f[10010];
void init()
{
    for (int i=0;i<1<<limit;i++)
        cnt[i]=__builtin_popcount(i)-1;
}
int calc(int start,int n,int m)
{
    for (int i=0;i<n;i++)
    {
        p[i]=a[start+i];
        q[i]=b[start+i];
    }
    for (int i=1;i<1<<n;i++)
    {
        g[i]=1<<30;
        int x=cnt[i];
        for (int j=0;j<n;j++)
        {
            if (!(i>>j&1) || abs(p[x]-q[j])<m)
                continue;
            g[i]=min(g[i],g[i^1<<j]+abs(p[x]-q[j]));
        }
    }
    return(g[(1<<n)-1]);
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            scanf("%d%d",&a[i],&b[i]);
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        memset(f,63,sizeof(f));
        int inf=f[0];
        f[0]=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=min(i,limit);j++)
                f[i]=min(f[i],f[i-j]+calc(i-j+1,j,m));
        static int id=0;
        printf("Case %d: ",++id);
        if (f[n]==inf)
            printf("impossible\n");
        else
            printf("%d\n",f[n]);
    }
    return(0);
}

