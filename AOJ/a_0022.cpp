#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    while (1)
    {
        int n,ans,now;
        scanf("%d",&n);
        if (n==0)
            break;
        ans=now=-1<<30;
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            now=max(now,0)+x;
            ans=max(ans,now);
        }
        printf("%d\n",ans);
    }
    return(0);
}

