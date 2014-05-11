#include <cstdio>
#include <algorithm>
using namespace std;
int Log[510],f[10][510][510];
void init()
{
    Log[1]=0;
    for (int i=2;i<=500;i++)
    {
        Log[i]=Log[i-1];
        if (i&i-1)
            continue;
        Log[i]++;
    }
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,Q;
        scanf("%d%d",&n,&Q);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                scanf("%d",&f[0][i][j]);
        for (int i=1;i<=Log[n];i++)
            for (int j=1;j<=n;j++)
            {
                if (j+(1<<i)-1>n)
                    break;
                for (int k=1;k<=n;k++)
                {
                    if (k+(1<<i)-1>n)
                        break;
                    int u=j+(1<<i-1),v=k+(1<<i-1);
                    f[i][j][k]=max(max(f[i-1][j][k],f[i-1][u][k]),max(f[i-1][j][v],f[i-1][u][v]));
                }
            }
        static int id=0;
        printf("Case %d:\n",++id);
        while (Q--)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            int t=Log[z],u=x+z-(1<<t),v=y+z-(1<<t);
            printf("%d\n",max(max(f[t][x][y],f[t][u][y]),max(f[t][x][v],f[t][u][v])));
        }
    }
    return(0);
}

