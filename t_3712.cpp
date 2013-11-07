#include <cstdio>
#include <algorithm>
using namespace std;
int a[10010],f[10010],g[10010];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    f[1]=1;
    for (int i=2;i<=n;i++)
        if (a[i]>=a[i-1])
            f[i]=f[i-1]+1;
        else
            f[i]=1;
    g[n]=1;
    for (int i=n-1;i;i--)
        if (a[i]>=a[i+1])
            g[i]=g[i+1]+1;
        else
            g[i]=1;
    int ans=0;
    for (int i=1;i<=n;i++)
        ans=max(ans,f[i]+g[i]-1);
    printf("%d\n",ans);
    return(0);
}

