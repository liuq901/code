#include <cstdio>
#include <cstdlib>
#include <cstring>
int a[20],f[20][20];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        memset(f,0,sizeof(f));
        for (int i=1;i<=m;i++)
        {
            scanf("%d",&a[i]);
            f[1][i]=1;
        }
        for (int i=2;i<=n;i++)
            for (int j=1;j<=m;j++)
                for (int k=1;k<=m;k++)
                    if (abs(a[j]-a[k])<=2)
                        f[i][k]+=f[i-1][j];
        int ans=0;
        for (int i=1;i<=m;i++)
            ans+=f[n][i];
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

