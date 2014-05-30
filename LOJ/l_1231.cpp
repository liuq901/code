#include <cstdio>
#include <cstring>
const int mod=100000007;
int a[1010],f[1010];
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
        memset(f,0,sizeof(f));
        f[0]=1;
        for (int i=1;i<=n;i++)
        {
            int K;
            scanf("%d",&K);
            for (int j=m;j>=a[i];j--)
                for (int k=1;k<=K;k++)
                {
                    if (a[i]*k>j)
                        break;
                    f[j]=(f[j]+f[j-a[i]*k])%mod;
                }
        }
        static int id=0;
        printf("Case %d: %d\n",++id,f[m]);
    }
    return(0);
}

