#include <cstdio>
typedef long long ll;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        ll n;
        scanf("%lld",&n);
        static int id=0;
        printf("Case %d: ",++id);
        if (n%2==1)
            printf("Impossible\n");
        else
        {
            ll ans=1;
            while (n%2==0)
            {
                ans<<=1;
                n>>=1;
            }
            printf("%lld %lld\n",n,ans);
        }
    }
    return(0);
}

