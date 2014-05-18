#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int m=500000;
int f[2][500010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        memset(f,-1,sizeof(f));
        f[0][0]=0;
        for (int i=1;i<=n;i++)
        {
            int x,u=i&1,v=u^1;
            scanf("%d",&x);
            for (int j=0;j<=m;j++)
            {
                if (f[v][j]==-1)
                    continue;
                f[u][j]=max(f[u][j],f[v][j]);
                f[u][j+x]=max(f[u][j+x],f[v][j]);
                if (x<=j)
                    f[u][j-x]=max(f[u][j-x],f[v][j]+x);
                else
                    f[u][x-j]=max(f[u][x-j],f[v][j]+j);
                f[v][j]=-1;
            }
        }
        static int id=0;
        printf("Case %d: ",++id);
        if (f[n&1][0]==0)
            printf("impossible\n");
        else
            printf("%d\n",f[n&1][0]);
    }
    return(0);
}

