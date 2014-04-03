#include <cstdio>
#include <cmath>
typedef long long ll;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        ll n;
        scanf("%lld",&n);
        ll x=ll(sqrt(double(n))+1e-8);
        if (x*x==n)
            x--;
        ll p=n-x*x;
        static int id=0;
        printf("Case %d: ",++id);
        if (x&1)
            if (p<=x)
                printf("%lld %lld\n",p,x+1);
            else
                printf("%lld %lld\n",x+1,2*x+2-p);
        else if (p<=x)
                printf("%lld %lld\n",x+1,p);
            else
                printf("%lld %lld\n",2*x+2-p,x+1);
    }
    return(0);
}

