#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int hp[20],f[32770];
char a[20][20];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&hp[i]);
        for (int i=1;i<=n;i++)
            scanf("%s",a[i]+1);
        memset(f,63,sizeof(f));
        int inf=f[0];
        f[0]=0;
        for (int i=0;i<1<<n;i++)
        {
            if (f[i]==inf)
                continue;
            for (int j=1;j<=15;j++)
            {
                if (i>>j-1&1)
                    continue;
                int now=1;
                for (int k=1;k<=15;k++)
                    if (i>>k-1&1)
                        now=max(now,a[k][j]-'0');
                f[i|1<<j-1]=min(f[i|1<<j-1],f[i]+(hp[j]+now-1)/now);
            }
        }
        static int id=0;
        printf("Case %d: %d\n",++id,f[(1<<n)-1]);
    }
    return(0);
}

