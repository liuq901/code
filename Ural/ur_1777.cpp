#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef multiset <ll>::iterator iter;
multiset <ll> a;
int main()
{
    for (int i=1;i<=3;i++)
    {
        ll x;
        scanf("%lld",&x);
        a.insert(x);
    }
    int sum=0;
    while (1)
    {
        ll ans=1LL<<60;
        for (iter k=a.begin();k!=a.end();k++)
        {
            if (k==a.begin())
                continue;
            iter p=k;
            p--;
            ans=min(ans,*k-*p);
        }
        a.insert(ans);
        sum++;
        if (ans==0)
            break;
    }
    printf("%d\n",sum);
    return(0);
}

