#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
typedef ll matrix[110][110];
const int mod=1000000007;
matrix f,zero,one,a;
ll l;
int m;
void dp(int n)
{
    for (int i=0;i<n;i++)
        for (int j=0;j<=m;j++)
        {
            if (f[i][j]==0)
                continue;
            int x=(i-j-j)%m;
            if (x<0)
                x+=m;
            int y=m-j-x;
            if (y<=0)
                continue;
            if (y==1)
                f[i+1][0]=(f[i+1][0]+f[i][j])%mod;
            else
                f[i+1][j]=(f[i+1][j]+f[i][j]*y)%mod;
            if (x>=1)
                f[i+1][j+1]=(f[i+1][j+1]+f[i][j]*x)%mod;
        }
}
void mul(matrix b,matrix c)
{
    matrix d={0};
    for (int i=0;i<=m;i++)
        for (int j=0;j<=m;j++)
            for (int k=0;k<=m;k++)
                d[i][j]=(d[i][j]+b[i][k]*c[k][j])%mod;
    for (int i=0;i<=m;i++)
        for (int j=0;j<=m;j++)
            a[i][j]=d[i][j];
}
void power(ll x)
{
    if (!x)
    {
        for (int i=0;i<=m;i++)
            for (int j=0;j<=m;j++)
                a[i][j]=zero[i][j];
        return;
    }
    power(x>>1);
    mul(a,a);
    if (x&1)
        mul(a,one);
}
void work()
{
    cin>>l>>m;
    for (int i=0;i<=m;i++)
    {
        memset(f,0,sizeof(f));
        f[0][i]=1;
        dp(m);
        for (int j=0;j<=m;j++)
            one[j][i]=f[m][j];
    }
    for (int i=0;i<=m;i++)
        zero[i][i]=1;
    power(l/m);
    for (int i=0;i<=m;i++)
        f[0][i]=a[i][0];
    dp(l%m);
    ll ans=0;
    for (int i=0;i<=m;i++)
        ans=(ans+f[l%m][i])%mod;
    cout<<ans<<endl;
}
int main()
{
    int T;
    cin>>T;
    while (T--)
        work();
    return(0);
}

