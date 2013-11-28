#include <cstdio>
int a[60];
int main()
{
    int n,K;
    scanf("%d%d",&n,&K);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int ans=0;
    for (int i=1;i<=K;i++)
    {
        if (a[i]<=0)
            break;
        ans++;
    }
    for (int i=K+1;i<=n;i++)
        if (a[i]>0 && a[i]==a[K])
            ans++;
    printf("%d\n",ans);
    return(0);
}

