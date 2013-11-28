#include <cstdio>
#include <algorithm>
using namespace std;
int a[510],f[510],g[510];
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int ans=0;
        for (int i=n;i;i--)
        {
            f[i]=g[i]=1;
            for (int j=i+1;j<=n;j++)
            {
                if (a[i]>=a[j])
                    f[i]=max(f[i],f[j]+1);
                if (a[i]<=a[j])
                    g[i]=max(g[i],g[j]+1);
            }
            ans=max(ans,max(f[i],g[i]));
            for (int j=i+1;j<=n;j++)
            {
                if (a[i]<a[j])
                    ans=max(ans,f[i]+g[j]);
                if (a[i]>a[j])
                    ans=max(ans,f[j]+g[i]);
            }
        }
        printf("%d\n",ans);
    }
    return(0);
}

