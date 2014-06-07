#include <cstdio>
#include <cstring>
typedef long long ll;
int a[15][15];
ll f[1<<15][3];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        memset(f,0,sizeof(f));
        f[0][1]=1;
        for (int i=0;i<1<<n;i++)
            for (int j=0;j<3;j++)
            {
                if (f[i][j]==0)
                    continue;
                int x=__builtin_popcount(i);
                for (int k=0;k<n;k++)
                {
                    if (i>>k&1)
                        continue;
                    int y=a[x][k];
                    if (j==0)
                        f[i|1<<k][y==2?2:0]+=f[i][j];
                    else if (j==1)
                        f[i|1<<k][y]+=f[i][j];
                    else
                        f[i|1<<k][2]+=f[i][j];
                }
            }
        static int id=0;
        printf("Case %d: %lld\n",++id,f[(1<<n)-1][1]+f[(1<<n)-1][2]);
    }
    return(0);
}

