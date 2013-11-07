#include <cstdio>
#include <algorithm>
using namespace std;
int a[200010],c[200010],v[200010],f[200010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        v[n]=1;
        for (int i=n-1;i;i--)
            v[i]=a[i]<a[i+1]?v[i+1]+1:1;
        c[0]=f[0]=a[0]=0;
        int m=1,ans=0;
        for (int i=1;i<=n;i++)
        {
            int p=lower_bound(c,c+m,a[i])-c;
            ans=max(ans,v[i]+p-1);
            f[i]=a[i]>a[i-1]?f[i-1]+1:1;
            if (f[i]==m)
                c[m++]=a[i];
            else
                c[f[i]]=min(c[f[i]],a[i]);
        }
        printf("%d\n",ans);
    }
    return(0);
}

