#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,mi,a[310][310],f[2][310][310];
int calc(int x0,int y0,int x1,int y1)
{
    if (x0==0 || x0>n || y0==0 || y0>n || x1==0 || x1>n || y1==0 || y1>n)
        return(mi);
    if (x0==x1 && y0==y1)
        return(a[x0][y0]);
    return(a[x0][y0]+a[x1][y1]);
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    memset(f,-63,sizeof(f));
    mi=f[0][0][0];
    f[0][1][1]=a[1][1];
    for (int i=2;i<n+n;i++)
    {
        int u=i&1,v=u^1;
        for (int j=1;j<=n;j++)
            for (int k=1;k<=n;k++)
            {
                int x=i-j,y=i-k;
                if (x>=1 && x<=n && y>=1 && y<=n && f[u][j][k]!=mi)
                {
                    f[v][j][k]=max(f[v][j][k],f[u][j][k]+calc(j,x+1,k,y+1));
                    f[v][j][k+1]=max(f[v][j][k+1],f[u][j][k]+calc(j,x+1,k+1,y));
                    f[v][j+1][k]=max(f[v][j+1][k],f[u][j][k]+calc(j+1,x,k,y+1));
                    f[v][j+1][k+1]=max(f[v][j+1][k+1],f[u][j][k]+calc(j+1,x,k+1,y));
                    f[u][j][k]=mi;
                }
            }
    }
    printf("%d\n",f[n+n&1][n][n]);
    return(0);
}

