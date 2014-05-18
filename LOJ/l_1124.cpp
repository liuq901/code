#include <cstdio>
typedef long long ll;
const int mod=100000007;
int a[20],fac[1000020],inv[1000020];
int power(int x,int y)
{
    int ret=1;
    for (;y;y>>=1)
    {
        if (y&1)
            ret=ll(ret)*x%mod;
        x=ll(x)*x%mod;
    }
    return(ret);
}
void init()
{
    const int n=1000010;
    fac[0]=inv[0]=1;
    for (int i=1;i<=n;i++)
    {
        fac[i]=ll(fac[i-1])*i%mod;
        inv[i]=power(fac[i],mod-2);
    }
}
inline int C(int n,int m)
{
    return(ll(fac[n])*inv[m]%mod*inv[n-m]%mod);
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[i]=y-x;
            m-=x;
        }
        static int id=0;
        printf("Case %d: ",++id);
        if (m<0)
            printf("0\n");
        else
        {
            int ans=0;
            for (int i=0;i<1<<n;i++)
            {
                int cnt=0,sum=m;
                for (int j=1;j<=n;j++)
                    if (i>>j-1&1)
                    {
                        cnt++;
                        sum-=a[j]+1;
                    }
                if (sum>=0)
                {
                    int now=C(sum+n-1,n-1);
                    if (cnt&1)
                        ans=(ans-now+mod)%mod;
                    else
                        ans=(ans+now)%mod;
                }
            }
            printf("%d\n",ans);
        }
    }
    return(0);
}

