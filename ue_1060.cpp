#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        int cnt=(1+n)*n/2,ans=1<<30;
        for (int i=n&1?1:2;i<=n;i+=2)
        {
            int mid=i+n>>1,tot=(i+mid)*(mid-i+1)-mid;
            ans=min(ans,cnt-tot);
        }
        printf("%d\n",ans);
    }
    return(0);
}

