#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[20][20],f[16400];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                scanf("%d",&a[i][j]);
        memset(f,63,sizeof(f));
        f[0]=0;
        for (int i=0;i<1<<n;i++)
            for (int j=1;j<=n;j++)
            {
                if (i>>j-1&1)
                    continue;
                int now=a[j][j];
                for (int k=1;k<=n;k++)
                    if (i>>k-1&1)
                        now+=a[j][k];
                f[i|1<<j-1]=min(f[i|1<<j-1],f[i]+now);
            }
        static int id=0;
        printf("Case %d: %d\n",++id,f[(1<<n)-1]);
    }
    return(0);
}

