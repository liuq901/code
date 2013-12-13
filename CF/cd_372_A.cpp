#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[500010];
bool check(int K)
{
    for (int i=1;i<=K;i++)
        if (a[i]*2>a[n-K+i])
            return(false);
    return(true);
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int l=0,r=n/2,ans;
    while (l<=r)
    {
        int mid=l+r>>1;
        if (check(mid))
            ans=mid,l=mid+1;
        else
            r=mid-1;
    }
    printf("%d\n",n-ans);
    return(0);
}

