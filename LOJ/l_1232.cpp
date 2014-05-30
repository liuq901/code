#include <cstdio>
#include <cstring>
const int mod=100000007;
int f[10010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(f,0,sizeof(f));
        f[0]=1;
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            for (int j=x;j<=m;j++)
                f[j]=(f[j]+f[j-x])%mod;
        }
        static int id=0;
        printf("Case %d: %d\n",++id,f[m]);
    }
    return(0);
}

