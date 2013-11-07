#include <cstdio>
int f[1000];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        f[x]++;
    }
    int ans=0;
    for (int i=600;i<=700;i++)
        ans+=f[i]>>2;
    printf("%d\n",ans);
    return(0);
}

