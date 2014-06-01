#include <cstdio>
#include <algorithm>
using namespace std;
int w[20][20],a[16400],f[16400];
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
                scanf("%d",&w[i][j]);
        for (int i=0;i<1<<n;i++)
        {
            a[i]=0;
            for (int j=1;j<=n;j++)
            {
                if (!(i>>j-1&1))
                    continue;
                for (int k=j+1;k<=n;k++)
                    if (i>>k-1&1)
                        a[i]+=w[j][k]+w[k][j];
            }
        }
        for (int i=1;i<1<<n;i++)
        {
            f[i]=1<<30;
            for (int j=i;j;j=i&j-1)
                f[i]=min(f[i],f[i^j]+a[j]);
        }
        static int id=0;
        printf("Case %d: %d\n",++id,f[(1<<n)-1]);
    }
    return(0);
}

