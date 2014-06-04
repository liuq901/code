#include <cstdio>
int sg(int x)
{
    while (x&1)
        x>>=1;
    return(x>>1);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,ans=0;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            ans^=sg(x);
        }
        static int id=0;
        printf("Case %d: %s\n",++id,ans?"Alice":"Bob");
    }
    return(0);
}

