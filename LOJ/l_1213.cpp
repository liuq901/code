#include <cstdio>
int power(int x,int y,int mod)
{
    int ret=1;
    for (;y;y>>=1)
    {
        if (y&1)
            ret=ret*x%mod;
        x=x*x%mod;
    }
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,K,mod;
        scanf("%d%d%d",&n,&K,&mod);
        int sum=0;
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            sum+=x%mod;
        }
        sum%=mod;
        static int id=0;
        printf("Case %d: %d\n",++id,K%mod*power(n,K-1,mod)%mod*sum%mod);
    }
    return(0);
}

