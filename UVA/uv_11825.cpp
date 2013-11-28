#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,a[20][20],f[67000];
bool vis[20],b[67000];
bool check(int state)
{
    memset(vis,0,sizeof(vis));
    for (int i=1;i<=n;i++)
        if (state>>i-1&1)
        {
            vis[i]=true;
            for (int j=1;j<=a[i][0];j++)
                vis[a[i][j]]=true;
        }
    return(count(vis+1,vis+n+1,true)==n);
}
int main()
{
    while (1)
    {
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i][0]);
            for (int j=1;j<=a[i][0];j++)
            {
                scanf("%d",&a[i][j]);
                a[i][j]++;
            }
        }
        int limit=1<<n;
        for (int i=0;i<limit;i++)
            b[i]=check(i);
        memset(f,-63,sizeof(f));
        int ans=0;
        f[0]=0;
        for (int i=0;i<limit;i++)
        {
            if (b[i])
                f[i]=1;
            for (int j=i;j;j=i&j-1)
                f[i]=max(f[i],f[j]+f[i^j]);
            ans=max(ans,f[i]);
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

