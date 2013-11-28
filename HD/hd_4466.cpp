#include <cstdio>
typedef long long ll;
const int mod=1000000007,N=5000010;
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
char mu[N];
int f[N],g[N];
void init()
{
    int n=5000000;
    for (int i=3;i<=n;i++)
    {
        f[i]=f[i-1];
        int mi=(i+2)/3,ma=(i-1)/2;
        f[i]=(f[i]+ma-mi+1)%mod;
        if (i%2==0)
        {
            f[i]=(f[i]-i/4)%mod;
            if (f[i]<0)
                f[i]+=mod;
        }
    }
    mu[1]=1;
    for (int i=1;i<=n;i++)
        for (int j=2;i*j<=n;j++)
            mu[i*j]-=mu[i];
    for (int i=1;i<=n;i++)
        for (int j=1;i*j<=n;j++)
            g[i*j]+=f[i]*mu[j];
}
int main()
{
    init();
    int n;
    while (scanf("%d",&n)==1)
    {
        int ans=0;
        for (int i=1;i*i<=n;i++)
        {
            if (n%i!=0)
                continue;
            ans=(ans+ll(g[i])*power(2,n/i-1))%mod;
            if (n/i!=i)
                ans=(ans+ll(g[n/i])*power(2,i-1))%mod;
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

