#include <cstdio>
#include <cstring>
int p[100010];
bool f[100010];
void init()
{
    const int n=100000;
    for (int i=2;i*i<=n;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=n;j++)
        {
            f[i*j]=true;
            p[i*j]=i;
        }
    }
    for (int i=2;i<=n;i++)
        if (!f[i])
            p[i]=i;
}
int power(int x,int y,int mod)
{
    int ret=1;
    x%=mod;
    for (;y;y>>=1)
    {
        if (y&1)
            ret=ret*x%mod;
        x=x*x%mod;
    }
    return(ret);
}
int cnt[100010];
void work(int n,int delta)
{
    while (n>1)
    {
        cnt[p[n]]+=delta;
        n/=p[n];
    }
}
int calc(int n,int m,int mod)
{
    memset(cnt,0,sizeof(cnt));
    for (int i=1;i<=m;i++)
    {
        work(n-i+1,1);
        work(i,-1);
    }
    int ret=1;
    for (int i=1;i<=n;i++)
        ret=ret*power(i,cnt[i],mod)%mod;
    return(ret);
}
int solve(int n,int K,int L,int m)
{
    if (m==0)
        return(power(K,L,n));
    n<<=1;
    int ret=power(K,L,n)*power(K-1,m,n)%n*calc(L,m,n)%n;
    return(ret>>1);
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,K,L,m;
        scanf("%d%d%d%d",&n,&K,&L,&m);
        static int id=0;
        printf("Case %d: %d\n",++id,solve(n,K,L,m)+1);
    }
    return(0);
}

