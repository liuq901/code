#include <cstdio>
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        int ans=0;
        for (int i=1<<n-1;i<1<<n;i++)
            ans+=__builtin_popcount(i);
        printf("%d\n",ans);
    }
    return(0);
}

