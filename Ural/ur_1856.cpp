#include <cstdio>
#include <algorithm>
using namespace std;
int a[1010][2],cnt[1010][1010],b[1010][1010],q[2000010][3],p[2000010][3];
bool f[1010][1010][2];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        for (int j=0;j<=1;j++)
            scanf("%d",&a[i][j]);
    int tot=0;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
        {
            for (int k=0;k<=1;k++)
            {
                int x=min(a[i][k],a[j][k]),y=max(a[i][k],a[j][k]);
                p[++tot][0]=i,p[tot][1]=j,p[tot][2]=b[x][y],b[x][y]=tot;
            }
            cnt[i][j]=2;
        }
    int l=1,r=0;
    for (int i=1;i<=n;i++)
    {
        f[i][i][0]=f[i][i][1]=true;
        q[++r][0]=i,q[r][1]=i,q[r][2]=0;
        q[++r][0]=i,q[r][1]=i,q[r][2]=1;
    }
    while (l<=r)
    {
        int x0=q[l][0],y0=q[l][1],opt=q[l++][2];
        for (int i=b[x0][y0];i;i=p[i][2])
        {
            int x=p[i][0],y=p[i][1];
            if (f[x][y][1-opt])
                continue;
            if (opt==1)
            {
                f[x][y][0]=true;
                q[++r][0]=x,q[r][1]=y,q[r][2]=0;
            }
            else if (--cnt[x][y]==0)
            {
                f[x][y][1]=true;
                q[++r][0]=x,q[r][1]=y,q[r][2]=1;
            }
        }
    }
    bool flag=true;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            if (!f[i][j][0])
            {
                flag=false;
                break;
            }
    printf("%s\n",flag?"War":"Peace");
    return(0);
}

