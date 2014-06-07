#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mod=1000007;
int a[100010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int K,C,n;
        scanf("%d%d%d%d",&K,&C,&n,&a[1]);
        for (int i=2;i<=n;i++)
            a[i]=(ll(K)*a[i-1]+C)%mod;
        sort(a+1,a+n+1);
        ll ans=0;
        for (int i=1;i<n;i++)
            ans+=ll(a[i+1]-a[i])*i*(n-i);
        static int id=0;
        printf("Case %d: %lld\n",++id,ans);
    }
    return(0);
}

