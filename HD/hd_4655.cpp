#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mod=1000000007;
int a[1000010],b[1000010];
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
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int t=n;
        for (int i=1;i<n;i+=2)
        {
            b[i]=b[i+1]=a[t];
            t--;
        }
        int ans=n;
        for (int i=1;i<n;i++)
            ans=(ans-power(b[i],mod-2))%mod;
        for (int i=1;i<=n;i++)
            ans=ll(ans)*a[i]%mod;
        printf("%d\n",(ans+mod)%mod);
    }
    return(0);
}

