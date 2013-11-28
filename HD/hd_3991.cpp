#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int p[1010],t[1010],to[1010],a[110][110],b[1010][1010];
bool f[1010];
bool hungary(int x)
{
    if (x==0)
        return(true);
    for (int i=1;i<=b[x][0];i++)
    {
        int y=b[x][i];
        if (f[y])
            continue;
        f[y]=true;
        if (hungary(to[y]))
        {
            to[y]=x;
            return(true);
        }
    }
    return(false);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,Q;
        scanf("%d%d%d",&n,&m,&Q);
        memset(a,63,sizeof(a));
        for (int i=0;i<n;i++)
            a[i][i]=0;
        for (int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[x][y]=min(a[x][y],z);
            a[y][x]=min(a[y][x],z);
        }
        for (int k=0;k<n;k++)
            for (int i=0;i<n;i++)
                for (int j=0;j<n;j++)
                    a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
        for (int i=1;i<=Q;i++)
        {
            b[i][0]=0;
            scanf("%d%d",&p[i],&t[i]);
        }
        for (int i=1;i<=Q;i++)
            for (int j=1;j<=Q;j++)
            {
                if (t[i]>=t[j])
                    continue;
                int x=p[i],y=p[j];
                if (t[i]+a[x][y]<=t[j])
                    b[i][++b[i][0]]=j;
            }
        int ans=Q;
        memset(to,0,sizeof(to));
        for (int i=1;i<=Q;i++)
        {
            memset(f,0,sizeof(f));
            ans-=hungary(i);
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans-1);
    }
    return(0);
}

