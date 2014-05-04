#include <cstdio>
typedef long long ll;
const int mod=1000000007;
int power(int x,ll y)
{
    int ret=1;
    for (;y;y>>=1)
    {
        if (y&1)
            ret=ll(ret)*x%mod;
        x=ll(x)*x%mod;
    }
    return(ret);
}
bool f[50010];
int p[50010];
void init()
{
    int n=50000;
    for (int i=2;i*i<=n;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=n;j++)
            f[i*j]=true;
    }
    int tot=0;
    for (int i=2;i<=n;i++)
        if (!f[i])
            p[++tot]=i;
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int ans=1;
        for (int i=1;ll(p[i])*p[i]<=n;i++)
            if (n%p[i]==0)
            {
                ll cnt=0;
                while (n%p[i]==0)
                {
                    cnt+=m;
                    n/=p[i];
                }
                ans=ll(ans)*(power(p[i],cnt+1)-1)%mod*power(p[i]-1,mod-2)%mod;
            }
        if (n!=1)
            ans=ll(ans)*(power(n,m+1LL)-1)%mod*power(n-1,mod-2)%mod;
        static int id=0;
        printf("Case %d: %d\n",++id,(ans+mod)%mod);
    }
    return(0);
}

