#include <cstdio>
typedef long long ll;
int m,p[664580];
bool f[10000010];
void init()
{
    const int n=10000000;
    for (int i=2;i*i<=n;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=n;j++)
            f[i*j]=true;
    }
    for (int i=2;i<=n;i++)
        if (!f[i])
            p[++m]=i;
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        ll n,ans=1;
        scanf("%lld",&n);
        for (int i=1;i<=m;i++)
        {
            if (ll(p[i])*p[i]>n)
                break;
            int cnt=0;
            while (n%p[i]==0)
            {
                cnt++;
                n/=p[i];
            }
            ans*=2*cnt+1;
        }
        if (n!=1)
            ans*=3;
        static int id=0;
        printf("Case %d: %lld\n",++id,ans+1>>1);
    }
    return(0);
}

