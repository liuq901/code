#include <cstdio>
int a[110];
int main()
{
    int n,sum=0;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    int ans=0;
    for (int i=1;i<=n;i++)
        ans+=(sum-a[i])%2==0;
    printf("%d\n",ans);
    return(0);
}

