#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int n,b[20],a[10000][2];
ll f[17000][20];
ll calc(int x)
{
    memset(f,0,sizeof(f));
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        f[1<<y-1][y]=1;
    }
    for (int i=0;i<1<<n;i++)
        for (int j=1;j<=n;j++)
        {
            if (f[i][j]==0)
                continue;
            for (int k=b[j];k;k=a[k][1])
            {
                int y=a[k][0];
                if (i>>y-1&1)
                    continue;
                f[i|1<<y-1][y]+=f[i][j];
            }
        }
    ll sum=0,ret=0;
    for (int i=0;i<1<<n;i++)
    {
        int cnt=__builtin_popcount(i);
        if (cnt<3 || f[i][x]==0)
            continue;
        ret=max(ret,ll(cnt));
        sum+=f[i][x];
    }
    return(max(ret,sum/2));
}
int main()
{
    int m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[i][0]=y,a[i][1]=b[x],b[x]=i;
        a[i+m][0]=x,a[i+m][1]=b[y],b[y]=i+m;
    }
    ll ans=0;
    for (int i=1;i<=n;i++)
        ans=max(ans,calc(i));
    printf("%I64d\n",ans);
    return(0);
}

