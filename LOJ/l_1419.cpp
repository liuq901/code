#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mod=1000000007;
int power(int x,int y)
{
    int ret=1;
    for (;y;y>>=1)
    {
        if (y&1)
            ret=ll(ret)*x%mod;
        x=ll(x)*x%mod;
    }
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,K,ans=0;
        scanf("%d%d",&n,&K);
        for (int i=1;i<=n;i++)
            ans=(ans+power(K,__gcd(i,n)))%mod;
        static int id=0;
        printf("Case %d: %d\n",++id,ll(ans)*power(n,mod-2)%mod);
    }
    return(0);
}

