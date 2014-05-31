#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int b[110],a[210][3],f[110][110];
void dp(int x,int father,int m)
{
    memset(f[x],0,sizeof(f[x]));
    for (int i=b[x];i;i=a[i][2])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        dp(y,x,m);
        int tmp[110];
        memset(tmp,63,sizeof(tmp));
        for (int j=0;j<=m;j++)
        {
            tmp[j]=min(tmp[j],f[x][j]+f[y][m]+1);
            for (int k=a[i][1];k<=j;k++)
                tmp[j]=min(tmp[j],f[x][k-a[i][1]]+f[y][j-k]);
        }
        memcpy(f[x],tmp,sizeof(tmp));
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(b,0,sizeof(b));
        for (int i=1;i<n;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[i][0]=y,a[i][1]=z,a[i][2]=b[x],b[x]=i;
            a[i+n][0]=x,a[i+n][1]=z,a[i+n][2]=b[y],b[y]=i+n;
        }
        dp(1,0,m);
        static int id=0;
        printf("Case %d: %d\n",++id,f[1][m]+1);
    }
    return(0);
}

