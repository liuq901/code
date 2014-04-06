#include <cstdio>
typedef long long ll;
int m,p[1000010];
bool f[1000010];
void init()
{
    const int n=1000000;
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
        ll n;
        scanf("%lld",&n);
        ll ans=1;
        for (int i=1;i<=m;i++)
        {
            int x=p[i];
            if (ll(x)*x>n)
                break;
            int cnt=0;
            while (n%x==0)
            {
                cnt++;
                n/=x;
            }
            ans*=(cnt+1);
        }
        if (n!=1)
            ans<<=1;
        static int id=0;
        printf("Case %d: %lld\n",++id,ans-1);
    }
    return(0);
}

