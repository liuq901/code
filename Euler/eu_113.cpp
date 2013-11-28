#include <cstdio>
typedef long long ll;
ll f[110][10],g[110][10];
int n=100;
int main()
{
    for (int i=1;i<=9;i++)
        f[1][i]=g[1][i]=1;
    for (int i=2;i<=n;i++)
        for (int j=0;j<=9;j++)
            for (int k=0;k<=9;k++)
            {
                if (k>=j)
                    f[i][k]+=f[i-1][j];
                if (k<=j)
                    g[i][k]+=g[i-1][j];
            }
    ll ans=0;
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<=9;j++)
            ans+=f[i][j]+g[i][j];
        ans-=9;
    }
    printf("%lld\n",ans);
    return(0);
}

