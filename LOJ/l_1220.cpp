#include <cstdio>
typedef long long ll;
int calc(ll n,bool nega)
{
    for (int i=2;ll(i)*i<=n;i++)
    {
        ll now=1;
        int cnt=0;
        while (now<n)
        {
            now*=i;
            cnt++;
        }
        if (now==n && (!nega || cnt&1))
            return(cnt);
    }
    return(1);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        ll n;
        scanf("%lld",&n);
        bool nega=false;
        if (n<0)
        {
            nega=true;
            n*=-1;
        }
        static int id=0;
        printf("Case %d: %d\n",++id,calc(n,nega));
    }
    return(0);
}

