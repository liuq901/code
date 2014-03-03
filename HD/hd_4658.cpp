#include <cstdio>
#include <cstring>
typedef long long ll;
const int mod=1000000007;
int p[100010],sum[100010],q[2][100010];
void init()
{
    int n=100000;
    p[0]=1;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;;j++)
        {
            if (i-j*(3*j-1)/2<0)
                break;
            if (j&1)
                p[i]=(p[i]+p[i-j*(3*j-1)/2])%mod;
            else
                p[i]=(p[i]-p[i-j*(3*j-1)/2])%mod;
        }
        for (int j=-1;;j--)
        {
            if (i-j*(3*j-1)/2<0)
                break;
            if (j&1)
                p[i]=(p[i]+p[i-j*(3*j-1)/2])%mod;
            else
                p[i]=(p[i]-p[i-j*(3*j-1)/2])%mod;
        }
    }
    q[0][0]=1;
    for (int k=1;k<=450;k++)
    {
        memset(q[k&1],0,sizeof(q[k&1]));
        for (int i=k*(k+1)/2;i<=n;i++)
        {
            q[k&1][i]=(q[k-1&1][i-k]+q[k&1][i-k])%mod;
            if (k&1)
                sum[i]=(sum[i]-q[k&1][i])%mod;
            else
                sum[i]=(sum[i]+q[k&1][i])%mod;
        }
    }
}
int calc(int n,int K)
{
    int ans=p[n];
    for (int i=1;;i++)
    {
        if (n-K*i<0)
            break;
        ans=(ans+ll(p[n-K*i])*sum[i])%mod;
    }
    return((ans+mod)%mod);
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
        printf("%d\n",calc(n,K));
    }
    return(0);
}

