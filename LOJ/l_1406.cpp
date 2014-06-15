#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool a[20][20],flag[32770][20];
int n,f[32770];
void dfs(int x,int y)
{
    if (flag[x][y])
        return;
    flag[x][y]=flag[x][0]=true;
    for (int i=1;i<=n;i++)
        if (a[y][i])
            dfs(x|1<<i-1,i);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int m;
        scanf("%d%d",&n,&m);
        memset(a,0,sizeof(a));
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[x][y]=true;
        }
        memset(flag,0,sizeof(flag));
        for (int i=1;i<=n;i++)
            dfs(1<<i-1,i);
        memset(f,63,sizeof(f));
        f[0]=0;
        for (int i=0;i<1<<n;i++)
            for (int j=i;j;j=i&j-1)
                if (flag[j][0])
                    f[i]=min(f[i],f[i^j]+1);
        static int id=0;
        printf("Case %d: %d\n",++id,f[(1<<n)-1]);
    }
    return(0);
}

