#include <cstdio>
bool f[50010];
void init()
{
    int n=50000;
    for (int i=2;i*i<=n;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=n;j++)
            f[i*j]=true;
    }
}
int main()
{
    init();
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        int ans=0;
        for (int i=2;i<=n/2;i++)
            ans+=!f[i] && !f[n-i];
        printf("%d\n",ans);
    }
    return(0);
}

