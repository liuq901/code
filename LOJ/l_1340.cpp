#include <cstdio>
typedef long long ll;
const int mod=10000019;
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
bool f[100010];
int m,p[100010];
void init()
{
    const int n=100000;
    for (int i=2;i*i<=n;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=n;j++)
            f[i*j]=true;
    }
    for (int i=2;i<=n;i++)
        if (!f[i])
            p[++m]=i;
}
int solve(int n,int K)
{
    int ans=1;
    for (int i=1;i<=m;i++)
    {
        int tmp=n,cnt=0;
        while (tmp)
        {
            cnt+=tmp/p[i];
            tmp/=p[i];
        }
        ans=ll(ans)*power(p[i],cnt/K)%mod;
    }
    return(ans==1?-1:ans);
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,K;
        scanf("%d%d",&n,&K);
        static int id=0;
        printf("Case %d: %d\n",++id,solve(n,K));
    }
    return(0);
}

