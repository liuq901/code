#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a[10010];
void dfs(ll x)
{
    a[++a[0]]=x;
    if (x*10>1000000000LL)
        return;
    dfs(x*10+4);
    dfs(x*10+7);
}
int main()
{
    dfs(4);
    dfs(7);
    a[++a[0]]=4444444444LL;
    sort(a+1,a+a[0]+1);
    int l,r;
    scanf("%d%d",&l,&r);
    ll ans=0;
    for (int i=1;i<=a[0];i++)
    {
        if (l>r)
            break;
        if (a[i]<l)
            continue;
        int t=min(a[i],ll(r));
        ans+=a[i]*(t-l+1);
        l=t+1;
    }
    printf("%I64d\n",ans);
    return(0);
}

