#include <cstdio>
int a[110];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        a[x]++;
    }
    int ans=0;
    for (int i=1;i<=100;i++)
        ans+=a[i]>>1;
    printf("%d\n",ans>>1);
    return(0);
}

