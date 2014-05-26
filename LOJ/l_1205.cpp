#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll ans[20];
void init()
{
    for (int i=1;i<=17;i++)
    {
        ll p=1;
        int len=i+1>>1;
        for (int j=1;j<=len;j++)
            p*=10;
        ans[i]=p/10*9;
    }
}
int get(ll n,int a[])
{
    int len=0;
    while (n)
    {
        a[++len]=n%10;
        n/=10;
    }
    reverse(a+1,a+len+1);
    return(len);
}
ll calc(ll n)
{
    if (n<0)
        return(0);
    if (n==0)
        return(1);
    int a[20];
    int len=get(n,a);
    ll ret=0;
    for (int i=1;i<len;i++)
        ret+=ans[i];
    int m=len+1>>1;
    ll now=0,p=1;
    for (int i=1;i<=m;i++)
    {
        now=now*10+a[i];
        p*=10;
    }
    ret+=(now-p/10+1);
    ll tmp=0;
    for (int i=1;i<=m;i++)
        tmp=tmp*10+a[i];
    for (int i=m+1;i<=len;i++)
        tmp=tmp*10+a[len-i+1];
    return(ret+1-(n<tmp));
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        ll l,r;
        scanf("%lld%lld",&l,&r);
        if (l>r)
            swap(l,r);
        static int id=0;
        printf("Case %d: %lld\n",++id,calc(r)-calc(l-1));
    }
    return(0);
}

