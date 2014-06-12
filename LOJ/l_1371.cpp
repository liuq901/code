#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mod=1000000007;
int a[1010],b[1010];
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
        for (int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        int t=1,ans=1;
        for (int i=1;i<=n;i++)
        {
            while (t<=n && a[t]<=b[i])
                t++;
            if (t<i)
            {
                ans=0;
                break;
            }
            ans=ll(ans)*(t-i)%mod;
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

