#include <cstdio>
typedef long long ll;
int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        n++;
        ll ans=ll(n)*(n+1)/2;
        printf("%lld\n",ans*3-2*n);
    }
    return(0);
}

