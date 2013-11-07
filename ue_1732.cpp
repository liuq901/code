#include <cstdio>
#include <numeric>
using namespace std;
const int mod=1000007;
int f[110][110][110];
void init()
{
    f[0][0][0]=1;
    for (int i=0;i<=100;i++)
        for (int j=0;j<=100;j++)
            for (int k=0;k<=100;k++)
            {
                if (f[i][j][k]==0)
                    continue;
                for (int l=k;l<=100-i;l++)
                    f[i+l][j+1][l]=(f[i+l][j+1][l]+f[i][j][k])%mod;
            }
}
int main()
{
    init();
    int n,m;
    while (scanf("%d%d",&n,&m)==2)
        printf("%d\n",accumulate(f[n][m],f[n][m]+105,0)%mod);
    return(0);
}

