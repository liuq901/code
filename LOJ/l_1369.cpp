#include <cstdio>
typedef long long ll;
int a[100010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,Q;
        scanf("%d%d",&n,&Q);
        ll ans=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            ans+=(n-2*i+1LL)*a[i];
        }
        static int id=0;
        printf("Case %d:\n",++id);
        while (Q--)
        {
            int op;
            scanf("%d",&op);
            if (op==0)
            {
                int x,y;
                scanf("%d%d",&x,&y);
                int delta=y-a[++x];
                ans+=(n-2*x+1LL)*delta;
                a[x]=y;
            }
            else
                printf("%lld\n",ans);
        }
    }
    return(0);
}

