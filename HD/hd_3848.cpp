#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf=1000000000;
int ans,d[10010],b[10010],f[10010][2],a[20010][3];
void dfs(int x,int father)
{
    f[x][0]=f[x][1]=inf;
    for (int i=b[x];i;i=a[i][2])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        dfs(y,x);
        for (int j=0;j<2;j++)
        {
            int p=f[y][j]+a[i][1];
            if (p<f[x][0])
            {
                f[x][1]=f[x][0];
                f[x][0]=p;
            }
            else if (p<f[x][1])
                f[x][1]=p;
        }
    }
    if (f[x][0]==inf)
        f[x][0]=0;
    ans=min(ans,f[x][0]+f[x][1]);
}
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        memset(d,0,sizeof(d));
        memset(b,0,sizeof(b));
        for (int i=1;i<n;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[i][0]=y,a[i][1]=z,a[i][2]=b[x],b[x]=i;
            a[i+n][0]=x,a[i+n][1]=z,a[i+n][2]=b[y],b[y]=i+n;
            d[x]++,d[y]++;
        }
        if (n==2)
        {
            printf("%d\n",a[1][1]);
            continue;
        }
        int root;
        for (int i=1;i<=n;i++)
            if (d[i]>1)
            {
                root=i;
                break;
            }
        ans=inf;
        dfs(root,0);
        printf("%d\n",ans);
    }
    return(0);
}

