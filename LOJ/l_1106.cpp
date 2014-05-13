#include <cstdio>
#include <algorithm>
using namespace std;
int l[30],ans[30],a[30][200],f[30][200];
void print(int x,int y)
{
    if (a[x][y]==f[x][y])
    {
        ans[x]=y;
        return;
    }
    for (int i=y-l[x];i>=0;i--)
        if (f[x][y]==f[x+1][y-i-l[x]]+a[x][i])
        {
            ans[x]=i;
            print(x+1,y-i-l[x]);
            return;
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
        m*=12;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i][1]);
            ans[i]=0;
        }
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            for (int j=2;j<=m;j++)
                a[i][j]=max(a[i][j-1]-x,0);
            for (int j=2;j<=m;j++)
                a[i][j]+=a[i][j-1];
        }
        for (int i=1;i<n;i++)
            scanf("%d",&l[i]);
        for (int i=n;i;i--)
            for (int j=0;j<=m;j++)
            {
                f[i][j]=a[i][j];
                if (i==n)
                    continue;
                for (int k=0;k<=j-l[i];k++)
                    f[i][j]=max(f[i][j],f[i+1][j-k-l[i]]+a[i][k]);
            }
        static int id=0;
        printf("Case %d:\n",++id);
        print(1,m);
        for (int i=1;i<=n;i++)
            printf("%d%s",ans[i]*5,i==n?"\n":", ");
        printf("Number of fish expected: %d\n",f[1][m]);
    }
    return(0);
}

