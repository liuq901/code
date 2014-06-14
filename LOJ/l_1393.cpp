#include <cstdio>
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,ans=0;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                int x;
                scanf("%d",&x);
                if ((i+j&1)==(n+m&1))
                    continue;
                ans^=x;
            }
        static int id=0;
        printf("Case %d: %s\n",++id,ans?"win":"lose");
    }
    return(0);
}

