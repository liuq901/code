#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
double a[20][20],f[66000];
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
                scanf("%lf",&a[i][j]);
        memset(f,0,sizeof(f));
        for (int i=0;i<1<<n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                if (i>>j-1&1)
                    continue;
                for (int k=j+1;k<=n;k++)
                {
                    if (i>>k-1&1)
                        continue;
                    f[i|1<<j-1|1<<k-1]=max(f[i|1<<j-1|1<<k-1],f[i]+a[j][k]);
                }
            }
        }
        printf("%.2f\n",f[(1<<n)-1]);
    }
    return(0);
}

