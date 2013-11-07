#include <cstdio>
int main()
{
    int n;
    long long ans=0;
    scanf("%d",&n);
    for (int i=0;i<=n;i++)
        for (int j=i;j<=n;j++)
            ans+=i+j;
    printf("%lld\n",ans);
    return(0);
}

