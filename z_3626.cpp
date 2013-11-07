#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int m,v[110],b[110],a[210][3],f[110][210];
void dp(int x,int father)
{
    for (int i=0;i<=m;i++)
        f[x][i]=v[x];
    for (int i=b[x];i;i=a[i][2])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        dp(y,x);
        int t=a[i][1]*2;
        for (int j=m;j>=0;j--)
            for (int k=m;k>=0;k--)
                if (j-k-t>=0)
                   f[x][j]=max(f[x][j],f[x][j-k-t]+f[y][k]);
    }
}
int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        for (int i=1;i<=n;i++)
            scanf("%d",&v[i]);
        memset(b,0,sizeof(b));
        for (int i=1;i<n;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[i][0]=y,a[i][1]=z,a[i][2]=b[x],b[x]=i;
            a[i+n][0]=x,a[i+n][1]=z,a[i+n][2]=b[y],b[y]=i+n;
        }
        int root;
        scanf("%d%d",&root,&m);
        dp(root,0);
        printf("%d\n",f[root][m]);
    }
    return(0);
}

