#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double d=sqrt(2.0);
char f[1010][1010];
bool cross[1010][1010];
int main()
{
    int n,m,K;
    scanf("%d%d%d",&n,&m,&K);
    for (int i=1;i<=K;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        cross[x][y]=true;
    }
    for (int i=0;i<=n;i++)
        for (int j=0;j<=m;j++)
        {
            if (i)
                f[i][j]=max(f[i][j],f[i-1][j]);
            if (j)
                f[i][j]=max(f[i][j],f[i][j-1]);
            if (cross[i][j])
                f[i][j]=max(f[i][j],char(f[i-1][j-1]+1));
        }
    printf("%.0f\n",(n+m-2*f[n][m])*100+f[n][m]*100*d);
    return(0);
}

