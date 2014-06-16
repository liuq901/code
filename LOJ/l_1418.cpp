#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;
int X[10010],Y[10010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d%d",&X[i],&Y[i]);
        X[0]=X[n],Y[0]=Y[n];
        ll ans=0;
        for (int i=1;i<=n;i++)
            ans+=ll(X[i-1])*Y[i]-ll(Y[i-1])*X[i];
        ans=abs(ans);
        for (int i=1;i<=n;i++)
            ans-=__gcd(abs(X[i]-X[i-1]),abs(Y[i]-Y[i-1]));
        static int id=0;
        printf("Case %d: %lld\n",++id,ans+2>>1);
    }
    return(0);
}

