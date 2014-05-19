#include <cstdio>
#include <cstring>
typedef long long ll;
int a[100010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(a,0,sizeof(a));
        a[0]=1;
        ll ans=0;
        int sum=0;
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            sum=(sum+x)%m;
            ans+=a[sum];
            a[sum]++;
        }
        static int id=0;
        printf("Case %d: %lld\n",++id,ans);
    }
    return(0);
}

