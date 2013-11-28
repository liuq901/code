#include <cstdio>
int b[450],a[100010],c[100010],f[450][100010];
int main()
{
    int n,Q;
    scanf("%d%d",&n,&Q);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if (a[i]<=n)
            c[a[i]]++;
    }
    int m=0;
    for (int i=1;i<=n;i++)
        if (a[i]<=n && c[a[i]]>=a[i])
        {
            b[++m]=a[i];
            c[a[i]]=0;
        }
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
        {
            f[i][j]=f[i][j-1];
            if (b[i]==a[j])
                f[i][j]++;
        }
    while (Q--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        int ans=0;
        for (int i=1;i<=m;i++)
            ans+=(f[i][r]-f[i][l-1])==b[i];
        printf("%d\n",ans);
    }
    return(0);
}

