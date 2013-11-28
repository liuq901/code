#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int cnt[100010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        memset(cnt,0,sizeof(cnt));
        for (int i=1;i<=n;i++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            for (int j=l;j<=min(r,n);j++)
                cnt[j]++;
        }
        int ans=-1;
        for (int i=n;i;i--)
            if (i==cnt[i])
            {
                ans=i;
                break;
            }
        printf("%d\n",ans);
    }
    return(0);
}

