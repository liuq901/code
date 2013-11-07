#include <cstdio>
typedef long long ll;
const int mod=100000007;
int f[200010],inv[200010];
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
int C(int n,int m)
{
    return(ll(f[n])*inv[m]%mod*inv[n-m]%mod);
}
int to(int x1,int y1,int x2,int y2)
{
    int x=x2-x1,y=y2-y1;
    return(C(x+y,x));
}
int main()
{
    f[0]=1;
    for (int i=1;i<=200000;i++)
    {
        f[i]=ll(f[i-1])*i%mod;
        inv[i]=power(f[i],mod-2);
    }
    int m,n,p,q;
    while (scanf("%d%d%d%d",&m,&n,&p,&q)==4)
    {
        int ans=ll(to(0,0,m,n))*to(p,0,m,q)%mod;
        ans=(ans-ll(to(0,0,m,q))*to(p,0,m,n))%mod;
        ans=(ans+mod)%mod;
        printf("%d\n",ans);
    }
}

