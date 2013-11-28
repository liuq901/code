#include <cstdio>
#include <cstring>
typedef long long ll;
typedef ll matrix[3][3];
const int mod=1000000007;
matrix one,ans;
void multiply(matrix a,matrix b)
{
    matrix c;
    memset(c,0,sizeof(c));
    for (int i=1;i<=2;i++)
        for (int j=1;j<=2;j++)
            for (int k=1;k<=2;k++)
                c[i][k]=(c[i][k]+a[i][j]*b[j][k])%mod;
    memcpy(ans,c,sizeof(c));
}
void calc(ll n)
{
    if (n==1)
    {
        memcpy(ans,one,sizeof(one));
        return;
    }
    calc(n>>1);
    multiply(ans,ans);
    if (n&1)
        multiply(ans,one);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        ll n;
        scanf("%lld",&n);
        if (!n)
            printf("0\n");
        else if (n==1)
            printf("2\n");
        else
        {
            one[1][1]=0;
            one[1][2]=one[2][1]=one[2][2]=1;
            calc(n);
            ll x=ans[1][1]+ans[2][1],y=ans[1][2]+ans[2][2];
            printf("%lld\n",(x+y)%mod);
        }
    }
    return(0);
}

