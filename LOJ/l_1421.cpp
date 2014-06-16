#include <cstdio>
#include <algorithm>
using namespace std;
int c[100010],a[100010],f[100010],g[100010];
void calc(int n,int f[])
{
    int p=0;
    c[p]=-1<<30;
    for (int i=1;i<=n;i++)
    {
        int t=lower_bound(c,c+p+1,a[i])-c;
        f[i]=t;
        if (t==p+1)
            p++;
        c[t]=a[i];
    }
}
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
        calc(n,f);
        reverse(a+1,a+n+1);
        calc(n,g);
        reverse(g+1,g+n+1);
        int ans=0;
        for (int i=1;i<=n;i++)
            ans=max(ans,min(f[i],g[i])*2-1);
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

