#include <cstdio>
typedef long long ll;
bool f[10000010];
int m,p[10000010];
void init()
{
    for (int i=2;i*i<=10000000;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=10000000;j++)
            f[i*j]=true;
    }
    for (int i=2;i<=10000000;i++)
    {
        if (f[i])
            continue;
        p[++m]=i;
    }
}
ll mod;
ll mulmod(ll x,ll y)
{
    ll ret=0;
    for (;y;y>>=1)
    {
        if (y&1)
            ret=(ret+x)%mod;
        x=(x+x)%mod;
    }
    return(ret);
}
ll power(ll x,int y)
{
    ll ret=1;
    for (;y;y>>=1)
    {
        if (y&1)
            ret=mulmod(ret,x);
        x=mulmod(x,x);
    }
    return(ret);
}
int main()
{
    init();
    for (int i=1;i<=m;i++)
    {
        mod=ll(p[i])*p[i];
        ll now=(power(p[i]-1,i)+power(p[i]+1,i))%mod;
        if (now>10000000000LL)
        {
            printf("%d\n",i);
            break;
        }
    }
    return(0);
}

