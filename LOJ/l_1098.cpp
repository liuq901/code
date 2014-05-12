#include <cstdio>
typedef long long ll;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        ll ans=0;
        for (int i=2;i*i<=n;i++)
        {
            ans+=i;
            int x=i+1,y=n/i;
            if (y<x)
                continue;
            ans+=(y-x+1LL)*i+(x+y)*(y-x+1LL)/2;
        }
        static int id=0;
        printf("Case %d: %lld\n",++id,ans);
    }
    return(0);
}

