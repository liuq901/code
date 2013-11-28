#include <cstdio>
typedef long long ll;
const int mod=1000000007;
int a[10010],b[10010];
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
int main()
{
    int n,m1,m2;
    while (scanf("%d%d%d",&n,&m1,&m2)==3)
    {
        a[0]=b[0]=1;
        for (int i=1;i<=n;i++)
        {
            a[i]=ll(a[i-1])*(m1-i+1)%mod*power(i,mod-2)%mod;
            b[i]=ll(b[i-1])*(m2-i+1)%mod*power(i,mod-2)%mod;
        }
        int ans=0;
        for (int i=0;i<=n;i++)
            ans=(ans+ll(a[i])*b[n-i])%mod;
        printf("%d\n",ans);
    }
    return(0);
}

