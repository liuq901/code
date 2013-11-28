#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int a[40010];
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        ll ans=0;
        for (int i=1;i<=n;i++)
        {
            int same=upper_bound(a+1,a+n+1,a[i])-lower_bound(a+1,a+n+1,a[i]);
            ans+=n-same;
        }
        static int id=0;
        printf("Case %d: %lld\n",++id,ans/2);
    }
    return(0);
}

