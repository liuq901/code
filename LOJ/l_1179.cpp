#include <cstdio>
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int ans=0;
        for (int i=2;i<=n;i++)
            ans=(ans+m%i)%i;
        static int id=0;
        printf("Case %d: %d\n",++id,ans+1);
    }
    return(0);
}

