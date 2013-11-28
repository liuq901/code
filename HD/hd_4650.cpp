#include <cstdio>
#include <algorithm>
using namespace std;
const int inf=int(1e9);
int b[110],a[10010][3],f[110][110][110];
double g[110][110];
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)==2)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                for (int k=1;k<=n;k++)
                    f[i][j][k]=inf;
                g[i][j]=inf;
            }
            b[i]=0;
        }
        for (int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[i][0]=y,a[i][1]=z,a[i][2]=b[x],b[x]=i;
        }
        for (int i=1;i<=n;i++)
        {
            for (int j=b[i];j;j=a[j][2])
            {
                int x=a[j][0];
                f[i][1][x]=a[j][1];
            }
            for (int j=2;j<=n;j++)
                for (int k=1;k<=n;k++)
                {
                    if (f[i][j-1][k]==inf)
                        continue;
                    for (int l=b[k];l;l=a[l][2])
                    {
                        int x=a[l][0];
                        f[i][j][x]=min(f[i][j][x],f[i][j-1][k]+a[l][1]);
                    }
                }
        }
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                for (int k=1;k<=n;k++)
                {
                    if (f[i][j][k]==inf)
                        continue;
                    g[i][k]=min(g[i][k],f[i][j][k]/double(j));
                }
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                for (int k=1;k<=n;k++)
                    if (g[i][k]!=inf && g[k][j]!=inf && g[k][k]!=inf)
                        g[i][j]=min(g[i][j],g[k][k]);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            {
                if (g[i][j]==inf)
                    printf("NO");
                else
                    printf("%.3f",g[i][j]);
                printf("%c",j==n?'\n':' ');
            }
    }
    return(0);
}

