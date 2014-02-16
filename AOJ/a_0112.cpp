#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int a[10010];
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
        ll ans=0,sum=0;
        for (int i=1;i<=n;i++)
        {
            ans+=sum;
            sum+=a[i];
        }
        printf("%lld\n",ans);
    }
    return(0);
}

