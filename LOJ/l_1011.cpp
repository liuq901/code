#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int f[66000],a[20][20];
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
        memset(f,0,sizeof(f));
        f[0]=0;
        for (int i=0;i<1<<n;i++)
        {
            int p=__builtin_popcount(i)+1;
            for (int j=1;j<=n;j++)
            {
                if (i>>j-1&1)
                    continue;
                f[i|1<<j-1]=max(f[i|1<<j-1],f[i]+a[j][p]);
            }
        }
        static int id=0;
        printf("Case %d: %d\n",++id,f[(1<<n)-1]);
    }
    return(0);
}

