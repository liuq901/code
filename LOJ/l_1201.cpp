#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int b[1010],f[1010][2],a[2010][2];
int dp(int x,int father)
{
    f[x][0]=0;
    f[x][1]=1;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        dp(y,x);
        f[x][0]+=max(f[y][0],f[y][1]);
        f[x][1]+=f[y][0];
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[i][0]=y,a[i][1]=b[x],b[x]=i;
            a[i+n][0]=x,a[i+n][1]=b[y],b[y]=i+n;
        }
        memset(f,-1,sizeof(f));
        int ans=0;
        for (int i=1;i<=n;i++)
            if (f[i][0]==-1)
            {
                dp(i,0);
                ans+=max(f[i][0],f[i][1]);
            }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

