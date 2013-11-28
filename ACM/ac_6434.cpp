#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int a[110];
ll f[110][110];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        memset(f,63,sizeof(f));
        f[0][0]=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                for (int k=0;k<i;k++)
                    f[i][j]=min(f[i][j],f[k][j-1]+a[i]-a[k+1]);
        static int id=0;
        printf("Case #%d: %lld\n",++id,f[n][m]);
    }
    return(0);
}

