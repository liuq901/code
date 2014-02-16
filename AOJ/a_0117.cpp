#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[30][30];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    memset(a,63,sizeof(a));
    for (int i=1;i<=m;i++)
    {
        int x,y,u,v;
        scanf("%d,%d,%d,%d",&x,&y,&u,&v);
        a[x][y]=min(a[x][y],u);
        a[y][x]=min(a[y][x],v);
    }
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
    int S,T,t1,t2;
    scanf("%d,%d,%d,%d",&S,&T,&t1,&t2);
    printf("%d\n",t1-t2-a[S][T]-a[T][S]);
    return(0);
}

