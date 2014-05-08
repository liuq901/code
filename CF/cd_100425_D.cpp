#include <cstdio>
#include <utility>
using namespace std;
typedef long long ll;
pair <ll,ll> calc(ll n,ll x)
{
    if (n==0)
        return(make_pair(0,0));
    if (x==1)
        return(make_pair(n/2+n%2,n/2));
    pair <ll,ll> tmp=calc(n-1,(x+1)/2);
    if (x%2==n%2)
        tmp.first++;
    else
        tmp.second++;
    return(tmp);
}
int main()
{
    ll n;
    int Q;
    scanf("%I64d%*d%*d%d",&n,&Q);
    while (Q--)
    {
        ll x;
        scanf("%I64d",&x);
        pair <ll,ll> ans=calc(n,x);
        printf("%I64d %I64d\n",ans.first,ans.second);
    }
    return(0);
}

