#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int ans=0,now=0,n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        now+=y-x;
        ans=max(ans,now);
    }
    printf("%d\n",ans);
    return(0);
}

