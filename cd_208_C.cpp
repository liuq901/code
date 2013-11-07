#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int a[110][110];
ll b[110][110];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    memset(a,63,sizeof(a));
    memset(b,0,sizeof(b));
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[x][y]=a[y][x]=1;
        b[x][y]=b[y][x]=1;
    }
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            {
                if (a[i][k]+a[k][j]<a[i][j])
                {
                    a[i][j]=a[i][k]+a[k][j];
                    b[i][j]=0;
                }
                if (a[i][k]+a[k][j]==a[i][j])
                    b[i][j]+=b[i][k]*b[k][j];
            }
    double ans=1;
    for (int i=2;i<n;i++)
        if (a[1][i]+a[i][n]==a[1][n])
            ans=max(ans,2.0*b[1][i]*b[i][n]/b[1][n]);
    printf("%.10f\n",ans);
    return(0);
}

