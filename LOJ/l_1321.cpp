#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
double a[110][110];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,S,K;
        scanf("%d%d%d%d",&n,&m,&S,&K);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                a[i][j]=-1e100;
        for (int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            x++,y++;
            a[x][y]=a[y][x]=log(z/100.0);
        }
        for (int k=1;k<=n;k++)
            for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++)
                    a[i][j]=max(a[i][j],a[i][k]+a[k][j]);
        static int id=0;
        printf("Case %d: %.10f\n",++id,exp(log(2.0*S*K)-a[1][n]));
    }
    return(0);
}

