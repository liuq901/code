#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n,ans=0,now=0;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        now=max(0,now+x);
        ans=max(ans,now);
    }
    printf("%d\n",ans);
    return(0);
}

