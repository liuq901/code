#include <cstdio>
#include <cstring>
bool a[12][12];
int ans[12],f[1<<12][12][12];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,Q;
        scanf("%d%d%d",&n,&m,&Q);
        memset(a,0,sizeof(a));
        for (int i=0;i<n;i++)
        {
            int K;
            scanf("%d",&K);
            for (int j=1;j<=K;j++)
            {
                int x;
                scanf("%d",&x);
                x--;
                a[i][x]=true;
            }
        }
        memset(f,0,sizeof(f));
        for (int i=0;i<n;i++)
            f[1<<i][0][i]=1;
        for (int i=0;i<1<<n;i++)
            for (int j=0;j<n;j++)
                for (int k=0;k<n;k++)
                {
                    if (f[i][j][k]==0)
                        continue;
                    for (int l=0;l<n;l++)
                    {
                        if (i>>l&1)
                            continue;
                        f[i|1<<l][j+a[l][k]][l]+=f[i][j][k];
                    }
                }
        memset(ans,0,sizeof(ans));
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                ans[i]+=f[(1<<n)-1][i][j];
        for (int i=1;i<n;i++)
            ans[i]+=ans[i-1];
        static int id=0;
        printf("Case %d:\n",++id);
        while (Q--)
        {
            int x;
            scanf("%d",&x);
            if (m==0)
                x=n-1;
            else
            {
                x/=m;
                if (x>=n)
                    x=n-1;
            }
            printf("%d\n",ans[x]);
        }
    }
    return(0);
}

