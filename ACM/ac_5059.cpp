#include <cstdio>
typedef long long ll;
ll sg(ll x)
{
    if (x==1)
        return(0);
    if (x%2==0)
        return(x/2);
    return(sg(x/2));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        ll ans=0;
        for (int i=1;i<=n;i++)
        {
            ll x;
            scanf("%lld",&x);
            ans^=sg(x);
        }
        printf("%s\n",ans==0?"NO":"YES");
    }
    return(0);
}

