#include <cstdio>
#include <algorithm>
using namespace std;
int x1[110],y1[110],x2[110],y2[110];
int solve(int id,int n)
{
    int lx=-1<<30,rx=1<<30,ly=-1<<30,ry=1<<30;
    for (int i=1;i<=n;i++)
    {
        if (i==id)
            continue;
        lx=max(lx,x1[i]);
        rx=min(rx,x2[i]);
        ly=max(ly,y1[i]);
        ry=min(ry,y2[i]);
    }
    int x0=lx<=rx?rx-lx:0;
    int y0=ly<=ry?ry-ly:0;
    return(x0*y0);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
        int ans=0;
        for (int i=1;i<=n;i++)
            ans=max(ans,solve(i,n));
        printf("%d\n",ans);
    }
    return(0);
}

