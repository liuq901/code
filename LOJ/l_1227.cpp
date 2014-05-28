#include <cstdio>
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,P,Q,t=0,sum=0;
        scanf("%d%d%d",&n,&P,&Q);
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            sum+=x;
            if (sum<=Q && i<=P)
                t=i;
        }
        static int id=0;
        printf("Case %d: %d\n",++id,t);
    }
    return(0);
}

