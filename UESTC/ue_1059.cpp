#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll sqr(ll x)
{
    return(x*x);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int x0,y0,L,R,n,ans=0;
        scanf("%d%d%d%d%d",&x0,&y0,&L,&R,&n);
        for (int i=1;i<=n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            ll len=sqr(x-x0)+sqr(y-y0);
            if (len>=sqr(max(0,L-R)) && len<=sqr(L+R))
                ans++;
        }
        if (ans==n)
            printf("Oh yeah!\n");
        else if (ans==0)
            printf("Mom,I cannot touch it...555\n");
        else
            printf("%d\n",ans);
    }
    return(0);
}

