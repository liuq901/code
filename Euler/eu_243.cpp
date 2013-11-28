#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=1000000;
bool f[N+10];
int m,p[N+10];
void work()
{
    for (int i=2;i*i<=N;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=N;j++)
            f[i*j]=true;
    }
    for (int i=2;i<=N;i++)
        if (!f[i])
            p[++m]=i;
}
ll calc(ll x,int n)
{
    ll ret=x;
    for (int i=1;i<=n;i++)
        ret-=ret/p[i];
    return(ret);
}
ll ans=1LL<<60;
int main()
{
    work();
    ll now=1;
    for (int i=1;i<=m;i++)
    {
        now*=p[i];
        if (now>ans)
            break;
        ll tmp=now;
        while (1)
        {
            if (calc(tmp,i)*94744<(tmp-1)*15499)
                break;
            tmp<<=1;
        }
        ans=min(ans,tmp);
    }
    printf("%lld\n",ans);
    return(0);
}

