#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
vector <ll> calc(ll x)
{
    vector <ll> ret;
    for (int i=2;ll(i)*i<=x;i++)
    {
        if (x%i!=0)
            continue;
        ret.push_back(i);
        while (x%i==0)
            x/=i;
    }
    if (x!=1)
        ret.push_back(x);
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        ll a,b;
        scanf("%I64d%I64d",&a,&b);
        static int id=0;
        printf("Case #%d: %s\n",++id,calc(a)==calc(b)?"YES":"NO");
    }
    return(0);
}

