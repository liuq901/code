#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int d[150][150],f[150][150];
bool same(int N)
{
    for (int i=0;i<N;i++)
        for (int j=0;j<N;j++)
            if (f[i][j]!=d[i][j])
                return(false);
    return(true);
}
int main()
{
    memset(d,63,sizeof(d));
    int inf=d[0][0],n,K,m;
    scanf("%d%d%d",&n,&K,&m);
    for (int i=1;i<=m;i++)
    {
        int x1,y1,x2,y2;
        scanf("%d.%d - %d.%d",&x1,&y1,&x2,&y2);
        int x=x1*n+y1,y=x2*n+y2;
        d[x][y]=d[y][x]=1;
    }
    int N=(K+1)*n;
    for (int i=0;i<N;i++)
        d[i][i]=0;
    while (1)
    {
        memset(f,63,sizeof(f));
        for (int i=0;i<N;i++)
            f[i][i]=0;
        for (int i=1;i<=K;i++)
            for (int j=0;j<n;j++)
                for (int k=0;k<n;k++)
                    f[i*n+j][i*n+k]=d[j][k];
        for (int i=0;i<N;i++)
            for (int j=0;j<N;j++)
                f[i][j]=min(f[i][j],d[i][j]);
        for (int k=0;k<N;k++)
            for (int i=0;i<N;i++)
                for (int j=0;j<N;j++)
                    f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
        if (same(N))
            break;
        for (int i=0;i<N;i++)
            for (int j=0;j<N;j++)
                d[i][j]=f[i][j];
    }
    int S,T;
    scanf("%d%d",&S,&T);
    if (d[S][T]==inf)
        printf("no solution\n");
    else
        printf("%d\n",d[S][T]);
    return(0);
}

