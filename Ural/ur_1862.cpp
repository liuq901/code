#include <cstdio>
#include <cstring>
typedef long long ll;
typedef int matrix[6][6];
const int mod=1000000007;
const int a[6]={2,1,2,2,0,2};
const matrix one={{4,0,4,0,1,0},{8,4,4,4,0,0},{0,0,2,0,1,0},{0,0,2,2,0,0},{0,0,0,0,1,0},{2,1,2,2,0,2}};
matrix zero,ret,tmp;
void mul(matrix ret,matrix a,matrix b)
{
    matrix c;
    memset(c,0,sizeof(c));
    for (int k=0;k<6;k++)
        for (int i=0;i<6;i++)
        {
            if (a[i][k]==0)
                continue;
            for (int j=0;j<6;j++)
                c[i][j]=(c[i][j]+ll(a[i][k])*b[k][j])%mod;
        }
    memcpy(ret,c,sizeof(c));
}
void power(ll n)
{
    memcpy(ret,zero,sizeof(zero));
    memcpy(tmp,one,sizeof(one));
    for (;n;n>>=1)
    {
        if (n&1)
            mul(ret,ret,tmp);
        mul(tmp,tmp,tmp);
    }
}
int main()
{
    ll n;
    scanf("%lld",&n);
    for (int i=0;i<6;i++)
        zero[i][i]=1;
    power(n-1);
    int ans=0;
    for (int i=0;i<6;i++)
        ans=(ans+ll(a[i])*ret[i][4])%mod;
    printf("%d\n",ans);
    return(0);
}

