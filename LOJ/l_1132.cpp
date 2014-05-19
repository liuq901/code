#include <cstdio>
#include <cstring>
typedef long long ll;
unsigned c[60][60],one[60][60];
void init()
{
    const int n=50;
    for (int i=0;i<=n;i++)
    {
        c[i][0]=c[i][i]=1;
        for (int j=1;j<i;j++)
            c[i][j]=c[i-1][j-1]+c[i-1][j];
    }
}
void multiply(unsigned a[][60],unsigned b[][60],unsigned c[][60],int m)
{
    unsigned d[60][60]={0};
    for (int i=0;i<m;i++)
        for (int j=0;j<m;j++)
            for (int k=0;k<m;k++)
                d[i][j]+=a[i][k]*b[k][j];
    memcpy(c,d,sizeof(d));
}
unsigned ans[60][60];
void power(ll n,int K)
{
    unsigned ret[60][60]={0};
    for (int i=0;i<K+2;i++)
        ret[i][i]=1;
    unsigned x[60][60];
    for (int i=0;i<=K;i++)
    {
        for (int j=0;j<=K;j++)
            x[i][j]=c[j][i];
        x[K+1][i]=0;
    }
    for (int i=0;i<K;i++)
        x[i][K+1]=0;
    x[K][K+1]=x[K+1][K+1]=1;
    for (;n;n>>=1)
    {
        if (n&1)
            multiply(ret,x,ret,K+2);
        multiply(x,x,x,K+2);
    }
    memcpy(ans,ret,sizeof(ret));
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        ll n;
        int K;
        scanf("%lld%d",&n,&K);
        power(n,K);
        static int id=0;
        unsigned sum=0;
        for (int i=0;i<=K;i++)
            sum+=ans[i][K+1];
        printf("Case %d: %u\n",++id,sum);
    }
    return(0);
}

