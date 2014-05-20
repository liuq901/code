#include <cstdio>
typedef long long ll;
ll calc(ll n)
{
    if (n<0)
        return(0);
    if (n<10)
        return(1);
    ll p=1;
    int cnt=0;
    while (p<=n)
    {
        p*=10;
        cnt++;
    }
    cnt--,p/=10;
    ll ret=0,tmp=1;
    for (int i=1;i<=cnt;i++)
    {
        ret+=i==1?1:tmp*9*(i-1)/10;
        tmp*=10;
    }
    for (int i=0;i<=cnt;i++)
    {
        int tmp=n/p%10;
        for (int j=i?0:1;j<tmp;j++)
            ret+=p*(cnt-i)/10;
        if (i)
            ret+=tmp==0?n%p+1:p;
        p/=10;
    }
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        ll m,n;
        scanf("%lld%lld",&m,&n);
        static int id=0;
        printf("Case %d: %lld\n",++id,calc(n)-calc(m-1));
    }
    return(0);
}

