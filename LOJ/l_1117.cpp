#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int a[20];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=m;i++)
            scanf("%d",&a[i]);
        ll ans=n;
        for (int i=1;i<1<<m;i++)
        {
            ll now=-1;
            int cnt=0;
            for (int j=1;j<=m;j++)
                if (i>>j-1&1)
                {
                    cnt++;
                    if (now==-1)
                        now=a[j];
                    else if (now<=n)
                    {
                        ll p=__gcd(now,ll(a[j]));
                        now*=a[j]/p;
                    }
                }
            now=n/now;
            if (cnt&1)
                ans-=now;
            else
                ans+=now;
        }
        static int id=0;
        printf("Case %d: %lld\n",++id,ans);
    }
    return(0);
}

