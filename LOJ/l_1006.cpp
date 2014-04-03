#include <cstdio>
const int mod=10000007;
int a[10010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        for (int i=0;i<=5;i++)
        {
            scanf("%d",&a[i]);
            a[i]%=mod;
            if (a[i]<0)
                a[i]+=mod;
        }
        int n;
        scanf("%d",&n);
        for (int i=6;i<=n;i++)
            a[i]=(a[i-1]+a[i-2]+a[i-3]+a[i-4]+a[i-5]+a[i-6])%mod;
        static int id=0;
        printf("Case %d: %d\n",++id,a[n]);
    }
    return(0);
}

