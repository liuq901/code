#include <cstdio>
typedef long long ll;
int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        int x=n/2;
        ll ans=ll(x)*(n-x);
        printf("%lld\n",ans);
    }
    return(0);
}

