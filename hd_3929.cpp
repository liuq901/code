#include <cstdio>
typedef long long ll;
int calc(ll x)
{
    int ret=0;
    while (x)
    {
        ret+=x&1;
        x>>=1;
    }
    return(ret);
}
ll a[20],s[33000];
int c[33000];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%I64d",&a[i]);
        ll ans=0;
        for (int i=1;i<1<<n;i++)
        {
            ll sum=-1;
            int cnt=0;
            for (int j=1;j<=n;j++)
                if (i>>j-1&1)
                {
                    int p=i^1<<j-1;
                    if (p==0)
                    {
                        sum=a[j];
                        cnt=1;
                    }
                    else
                    {
                        sum=s[p]&a[j];
                        cnt=c[p]+1;
                    }
                    break;
                }
            s[i]=sum;
            c[i]=cnt;
            int p;
            if (cnt&1)
                p=1;
            else
                p=-1;
            ans+=(1LL<<calc(sum))*p*(1<<cnt-1);
        }
        static int id=0;
        printf("Case #%d: %I64d\n",++id,ans);
    }
    return(0);
}

