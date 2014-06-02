#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a[110];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        int t=1;
        for (int i=62;i>=0;i--)
        {
            bool flag=false;
            for (int j=t;j<=n;j++)
                if (a[j]>>i&1)
                {
                    swap(a[j],a[t]);
                    flag=true;
                    break;
                }
            if (!flag)
                continue;
            for (int j=1;j<=n;j++)
                if (t!=j && a[j]>>i&1)
                    a[j]^=a[t];
            t++;
        }
        ll ans=0;
        for (int i=1;i<=n;i++)
            ans^=a[i];
        static int id=0;
        printf("Case %d: %lld\n",++id,ans);
    }
    return(0);
}

