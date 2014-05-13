#include <cstdio>
#include <algorithm>
using namespace std;
int a[100010],b[100010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,Q;
        scanf("%d%d",&n,&Q);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        static int id=0;
        printf("Case %d:\n",++id);
        while (Q--)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            l++,r++;
            if (r-l+1>1000)
            {
                printf("0\n");
                continue;
            }
            int m=0;
            for (int i=l;i<=r;i++)
                b[++m]=a[i];
            sort(b+1,b+m+1);
            int ans=1<<30;
            for (int i=2;i<=m;i++)
                ans=min(ans,b[i]-b[i-1]);
            printf("%d\n",ans);
        }
    }
    return(0);
}

