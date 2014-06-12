#include <cstdio>
typedef unsigned long long ull;
ull a[3000010],ans[3000010];
void init()
{
    const int n=3000000;
    for (int i=1;i<=n;i++)
        a[i]=i*(i+1LLU)/2;
    for (int i=1;i<=n;i++)
        for (int j=2;i*j<=n;j++)
            a[i*j]-=a[i]*j;
    for (int i=1;i<=n;i++)
        for (int j=1;i*j<=n;j++)
            ans[i*j]+=a[i];
    for (int i=1;i<=n;i++)
        ans[i]=ans[i-1]+ans[i]*i-i;
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
        static int id=0;
        printf("Case %d: %llu\n",++id,ans[n]);
    }
    return(0);
}

