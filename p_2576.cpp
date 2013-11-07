#include <cstdio>
#include <cstdlib>
bool f[60][45010];
int a[110];
int main()
{
    int n,m=0;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        m+=a[i];
    }
    f[0][0]=true;
    for (int i=1;i<=n;i++)
        for (int j=n>>1;j>=0;j--)
            for (int k=m;k>=0;k--)
                if (f[j][k])
                    f[j+1][k+a[i]]=true;
    int ans=0;
    for (int i=0;i<=m;i++)
    {
        if (!f[n>>1][i])
            continue;
        if (abs(m-(i<<1))<abs(m-(ans<<1)))
            ans=i;
    }
    if (ans>m-ans)
        ans=m-ans;
    printf("%d %d\n",ans,m-ans);
    return(0);
}

