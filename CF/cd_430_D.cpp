#include <cstdio>
#include <algorithm>
using namespace std;
int v[1010][1010],a[1010][1010],b[1010][1010],c[1010][1010],d[1010][1010];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            scanf("%d",&v[i][j]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            a[i][j]=max(a[i-1][j],a[i][j-1])+v[i][j];
    for (int i=1;i<=n;i++)
        for (int j=m;j;j--)
            b[i][j]=max(b[i-1][j],b[i][j+1])+v[i][j];
    for (int i=n;i;i--)
        for (int j=1;j<=m;j++)
            c[i][j]=max(c[i+1][j],c[i][j-1])+v[i][j];
    for (int i=n;i;i--)
        for (int j=m;j;j--)
            d[i][j]=max(d[i+1][j],d[i][j+1])+v[i][j];
    int ans=0;
    for (int i=2;i<n;i++)
        for (int j=2;j<m;j++)
            ans=max(ans,max(a[i][j-1]+b[i-1][j]+c[i+1][j]+d[i][j+1],a[i-1][j]+b[i][j+1]+c[i][j-1]+d[i+1][j]));
    printf("%d\n",ans);
    return(0);
}

