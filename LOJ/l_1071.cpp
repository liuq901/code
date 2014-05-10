#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int c[2][2]={{0,1},{1,0}};
int a[110][110],f[210][110][110];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
        memset(f,-63,sizeof(f));
        f[3][1][2]=a[1][1]+a[1][2]+a[2][1];
        for (int i=2;i<n+m;i++)
            for (int j=1;j<=n;j++)
                for (int k=j+1;k<=n;k++)
                {
                    int x=i-j,y=i-k;
                    if (x<=0 || x>m || y<=0 || y>m)
                        continue;
                    for (int p=0;p<2;p++)
                        for (int q=0;q<2;q++)
                        {
                            int u=j+c[p][0],v=x+c[p][1];
                            int s=k+c[q][0],t=y+c[q][1];
                            if (u<=0 || u>n || v<=0 || v>m || s<=0 || s>n || t<=0 || t>m || u==s && v==t)
                                continue;
                            f[i+1][u][s]=max(f[i+1][u][s],f[i][j][k]+a[u][v]+a[s][t]);
                        }
                }
        static int id=0;
        printf("Case %d: %d\n",++id,f[n+m-1][n-1][n]+a[n][m]);
    }
    return(0);
}

