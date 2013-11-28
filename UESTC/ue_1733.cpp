#include <cstdio>
typedef long long ll;
const int mod=123456781;
int f[1010][40];
void init()
{
    f[0][0]=1;
    for (int i=0;i<=1000;i++)
        for (int j=0;j<=30;j++)
        {
            if (f[i][j]==0)
                continue;
            f[i+1][j]=(f[i+1][j]+ll(f[i][j])*j)%mod;
            f[i+1][j+1]=(f[i+1][j+1]+f[i][j])%mod;
        }
}
int main()
{
    init();
    int n,K;
    while (scanf("%d%d",&n,&K)==2)
    {
        int ans=f[n][K];
        for (int i=1;i<=K;i++)
            ans=ll(ans)*i%mod;
        printf("%d\n",ans);
    }
    return(0);
}

