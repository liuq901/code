#include <cstdio>
typedef long long ll;
ll fac[40],c[40][40];
void init()
{
    int n=30;
    for (int i=0;i<=n;i++)
    {
        c[i][0]=c[i][i]=1;
        for (int j=1;j<i;j++)
            c[i][j]=c[i-1][j-1]+c[i-1][j];
    }
    fac[0]=1;
    for (int i=1;i<=n;i++)
        fac[i]=fac[i-1]*i;
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,K;
        scanf("%d%d",&n,&K);
        ll ans=n<K?0:c[n][K]*c[n][K]*fac[K];
        static int id=0;
        printf("Case %d: %lld\n",++id,ans);
    }
    return(0);
}

