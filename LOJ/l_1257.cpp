#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int b[30010],ans[30010],f[30010][2],a[60010][3];
void dp(int x,int father)
{
    for (int i=b[x];i;i=a[i][2])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        dp(y,x);
        if (f[y][0]+a[i][1]>f[x][0])
        {
            f[x][1]=f[x][0];
            f[x][0]=f[y][0]+a[i][1];
        }
        else if (f[y][0]+a[i][1]>f[x][1])
            f[x][1]=f[y][0]+a[i][1];
    }
}
void dfs(int x,int father,int up)
{
    ans[x]=max(f[x][0],up);
    for (int i=b[x];i;i=a[i][2])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        if (f[y][0]+a[i][1]==f[x][0])
            dfs(y,x,max(up,f[x][1])+a[i][1]);
        else
            dfs(y,x,max(up,f[x][0])+a[i][1]);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        memset(b,0,sizeof(b));
        for (int i=1;i<n;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            x++,y++;
            a[i][0]=y,a[i][1]=z,a[i][2]=b[x],b[x]=i;
            a[i+n][0]=x,a[i+n][1]=z,a[i+n][2]=b[y],b[y]=i+n;
        }
        memset(f,0,sizeof(f));
        dp(1,0);
        dfs(1,0,0);
        static int id=0;
        printf("Case %d:\n",++id);
        for (int i=1;i<=n;i++)
            printf("%d\n",ans[i]);
    }
    return(0);
}

