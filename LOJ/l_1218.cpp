#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int b[110],v[110],cover[110];
bool vis[110],choose[110],a[110][110];
bool hungary(int x,int n)
{
    if (x==0)
        return(true);
    for (int y=1;y<=n;y++)
    {
        if (vis[y] || !a[x][y] || cover[y])
            continue;
        vis[y]=true;
        if (hungary(b[y],n))
        {
            b[y]=x;
            return(true);
        }
    }
    return(false);
}
int calc(int n)
{
    memset(b,0,sizeof(b));
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        if (cover[i])
            continue;
        ans++;
        memset(vis,0,sizeof(vis));
        ans-=hungary(i,n);
    }
    return(ans);
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
            scanf("%d",&v[i]);
        sort(v+1,v+n+1);
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
                a[i][j]=v[j]%v[i]==0;
        memset(cover,0,sizeof(cover));
        int ans=calc(n);
        memset(choose,0,sizeof(choose));
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
                if (a[i][j] || a[j][i] || i==j)
                    cover[j]++;
            if (calc(n)==ans-1)
            {
                choose[i]=true;
                ans--;
            }
            else
                for (int j=i+1;j<=n;j++)
                    if (a[i][j] || a[j][i] || i==j)
                        cover[j]--;
        }
        static int id=0;
        printf("Case %d:",++id);
        for (int i=1;i<=n;i++)
            if (choose[i])
                printf(" %d",v[i]);
        printf("\n");
    }
    return(0);
}

