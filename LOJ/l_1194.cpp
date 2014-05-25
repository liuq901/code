#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
ll s[20],f[66000],c[20][20],cost[66000][20];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(c,0,sizeof(c));
        memset(s,0,sizeof(s));
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            for (int j=1;j<=m;j++)
                c[x][j]+=s[j];
            s[x]++;
        }
        memset(cost,0,sizeof(cost));
        for (int i=0;i<1<<m;i++)
            for (int j=1;j<=m;j++)
            {
                if (i>>j-1&1)
                    continue;
                for (int k=1;k<=m;k++)
                    if (i>>k-1&1)
                        cost[i][j]+=c[k][j];
            }
        memset(f,63,sizeof(f));
        f[0]=0;
        for (int i=0;i<1<<m;i++)
            for (int j=1;j<=m;j++)
            {
                if (i>>j-1&1)
                    continue;
                f[i|1<<j-1]=min(f[i|1<<j-1],f[i]+cost[i][j]);
            }
        static int id=0;
        printf("Case %d: %lld\n",++id,f[(1<<m)-1]);
    }
    return(0);
}

