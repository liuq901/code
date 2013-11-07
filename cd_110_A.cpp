#include <cstdio>
typedef long long ll;
int calc(ll x)
{
    int ret=0;
    while (x)
    {
        int p=x%10;
        x/=10;
        ret+=p==4 || p==7;

    }
    return(ret);
}
int main()
{
    ll n;
    scanf("%I64d",&n);
    printf("%s\n",calc(n)==4 || calc(n)==7?"YES":"NO");
    return(0);
}

