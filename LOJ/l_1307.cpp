#include <cstdio>
#include <algorithm>
using namespace std;
int a[2010];
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
        int ans=0;
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
            {
                int t=lower_bound(a+1,a+n+1,a[i]+a[j])-a-1;
                ans+=max(0,t-j);
            }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

