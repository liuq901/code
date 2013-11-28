#include <cstdio>
#include <algorithm>
using namespace std;
int a[100010];
int main()
{
    bool first=true;
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int ans=1,now=1;
        for (int i=2;i<=n;i++)
        {
            if (a[i]!=a[i-1])
            {
                ans=max(ans,now);
                now=1;
                continue;
            }
            now++;
        }
        ans=max(ans,now);
        if (!first)
            printf("\n");
        first=false;
        printf("%d\n",ans);
        for (int i=1;i<=ans;i++)
        {
            bool first=true;
            for (int j=i;j<=n;j+=ans)
            {
                if (!first)
                    printf(" ");
                first=false;
                printf("%d",a[j]);
            }
            printf("\n");
        }
    }
    return(0);
}

