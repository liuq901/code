#include <cstdio>
typedef long long ll;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        ll ans=0;
        for (int i=1;i<=n;i++)
        {
            ll sum=0;
            for (int j=1;j<=m;j++)
            {
                int x;
                scanf("%d",&x);
                sum+=x;
            }
            ans^=sum;
        }
        static int id=0;
        printf("Case %d: %s\n",++id,ans?"Alice":"Bob");
    }
    return(0);
}

