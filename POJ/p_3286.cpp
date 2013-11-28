#include <cstdio>
typedef long long ll;
typedef ll LL;
ll calc(ll n)
{
    if (n<0)
        return(0);
    ll ans=1;
    int t=0,a[20];
    for (;n;n/=10)
        a[++t]=n%10;
    int y=0,p=1,ret=0;
    for (int i=t;i>1;i--)
        y=y*10+a[i];
    for (int i=1;i<=t;i++)
    {
        ans+=(y-1)*p;
        if (a[i]>0)
            ans+=p;
        else
            ans+=(ret+1);
        y/=10,ret+=a[i]*p,p*=10;;
    }
    return(ans);
}
int main()
{
    while (1)
    {
        ll n,m;
        scanf("%I64d%I64d",&n,&m);
        if (n==-1 && m==-1)
            break;
        printf("%I64d\n",calc(m)-calc(n-1));
    }
    return(0);
}

