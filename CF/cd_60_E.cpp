#include <cstdio>
#include <cstring>
typedef long long ll;
typedef ll matrix[2][2];
int mod,a[1000010];
matrix one,zero,d;
void mul(matrix c,matrix a,matrix b)
{
    matrix p={0};
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++)
            for (int k=0;k<2;k++)
                p[i][j]=(p[i][j]+a[i][k]*b[k][j])%mod;
    memcpy(c,p,sizeof(p));
}
void power(ll x)
{
    memcpy(d,zero,sizeof(zero));
    for (;x;x>>=1)
    {
        if (x&1)
            mul(d,d,one);
        mul(one,one,one);
    }
}
ll work(int a0,int a1,ll x)
{
    one[0][0]=0,one[0][1]=one[1][0]=one[1][1]=1;
    power(x);
    return((a0*d[1][0]+a1*d[1][1])%mod);
}
int main()
{
    int n;
    ll x,y;
    scanf("%d%I64d%I64d%d",&n,&x,&y,&mod);
    zero[0][0]=zero[1][1]=1;
    ll sum=0;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum=(sum+a[i])%mod;
    }
    if (n==1)
        printf("%I64d\n",sum);
    else
    {
        one[0][1]=1,one[1][0]=-3,one[1][1]=4;    
        power(x);
        ll ans=(d[0][0]+2*d[0][1])%mod;
        ans=ans*(2*sum-a[1]-a[n])%mod;
        ans=(ans-sum+a[1]+a[n])%mod;
        sum=ans;
        ll low=a[1],high=work(a[n-1],a[n],x);
        one[0][0]=0,one[0][1]=1,one[1][0]=-3,one[1][1]=4;    
        power(y);
        ans=(d[0][0]+2*d[0][1])%mod;
        ans=ans*(2*sum-low-high)%mod;
        ans=(ans-sum+low+high)%mod;
        if (ans<0)
            ans+=mod;
        printf("%I64d\n",ans);
    }
    return(0);
}

