#include <cstdio>
bool f[10000010];
int m,p[700000];
void init()
{
    const int n=10000000;
    for (int i=2;i*i<=n;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=n;j++)
            f[i*j]=true;
    }
    for (int i=2;i<=n;i++)
        if (!f[i])
            p[++m]=i;
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        int ans=0;
        for (int i=1;i<=m;i++)
        {
            if (p[i]*2>n)
                break;
            ans+=!f[n-p[i]];
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

