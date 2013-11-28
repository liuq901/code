#include <cstdio>
#include <algorithm>
using namespace std;
const int limit=3000,inf=1<<26;
int b[110],a[210][3],g[limit+10],h[limit+10],f[110][limit+10];
void dp(int x,int m,int father)
{
    fill(f[x],f[x]+m+1,inf);
    f[x][0]=0;
    for (int i=b[x];i;i=a[i][2])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        dp(y,m,x);
        fill(g,g+m+1,inf);
        for (int T=1;T<=2;T++)
        {
            int cost=T==1?a[i][1]:a[i][1]-60;
            for (int j=0;j<=m;j++)
            {
                if (f[y][j]==inf)
                    continue;
                int len=max(0,j+cost);
                g[len]=min(g[len],max(0,f[y][j]-cost));
            }
        }
        fill(h,h+m+1,inf);
        for (int j=0;j<=m;j++)
        {
            if (f[x][j]==inf)
                continue;
            for (int k=0;k<=m-j;k++)
            {
                if (f[x][j]+g[k]>m)
                    continue;
                int len=max(j,k);
                h[len]=min(h[len],max(f[x][j],g[k]));
            }
        }
        copy(h,h+m+1,f[x]);
    }
}
bool check(int m)
{
    for (int i=0;i<=m;i++)
        if (f[1][i]!=inf)
            return(true);
    return(false);
}
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        fill(b+1,b+n+1,0);
        for (int i=1;i<n;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            z%=60;
            a[i][0]=y,a[i][1]=z,a[i][2]=b[x],b[x]=i;
            a[i+n][0]=x,a[i+n][1]=z,a[i+n][2]=b[y],b[y]=i+n;
        }
        int l=0,r=limit,ans;
        while (l<=r)
        {
            int mid=l+r>>1;
            dp(1,mid,0);
            if (check(mid))
                ans=mid,r=mid-1;
            else
                l=mid+1;
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

