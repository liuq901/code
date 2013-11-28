#include <cstdio>
int a[1010],f[1010],g[1010];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    f[1]=1;
    for (int i=2;i<=n;i++)
        f[i]=a[i]>=a[i-1]?f[i-1]+1:1;
    g[n]=1;
    for (int i=n-1;i;i--)
        g[i]=a[i]>=a[i+1]?g[i+1]+1:1;
    int ans=0;
    for (int i=1;i<=n;i++)
        if (f[i]+g[i]>ans)
            ans=f[i]+g[i];
    printf("%d\n",ans-1);
    return(0);
}

