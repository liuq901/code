#include <cstdio>
typedef long long ll;
const int mod=1000000007;
int f[1010][1010];
int main()
{
    for (int i=1;i<=1000;i++)
    {
        f[i][0]=1;
        for (int j=1;j<=i;j++)
            f[i][j]=(ll(f[i-1][j])*(j+1)+ll(f[i-1][j-1])*(i-j))%mod;
    }
    int n,K;
    while (scanf("%d%d",&n,&K)==2)
        printf("%d\n",f[n][K]);
    return(0);
}

