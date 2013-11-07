#include <cstdio>
typedef long long ll;
const int mod=10007*24;
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
        int n;
        scanf("%d",&n);
        int ans=power(n,8+54+12);
        ans=(ans+power(n,2+15+3)*6)%mod;
        ans=(ans+power(n,4+28+6)*3)%mod;
        ans=(ans+power(n,4+27+7)*6)%mod;
        ans=(ans+power(n,4+18+4)*8)%mod;
        static int id=0;
        printf("Case %d: %d\n",++id,ans/24);
    }
    return(0);
}

