#include <cstdio>
#include <cstdlib>
typedef long long ll;
ll calc(int x)
{
    ll ans=0;
    while (x)
    {
        ans=ans*10+x%10;
        x/=10;
    }
    return(ans);
}
int main()
{
    int n;
    scanf("%d",&n);
    ll ans=calc(abs(n));
    if (n<0)
        printf("-");
    printf("%I64d\n",ans);
    return(0);
}

