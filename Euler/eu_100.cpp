#include <cstdio>
typedef long long ll;
int main()
{
    ll x=15,y=21;
    while (1)
    {
        ll X=3*x+2*y-2;
        ll Y=4*x+3*y-3;
        if (y>1e12)
            break;
        x=X,y=Y;
    }
    printf("%lld\n",x);
    return(0);
}

