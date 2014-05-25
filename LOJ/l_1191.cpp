#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll f[60][60][60];
void init()
{
    int n=50;
    for (int i=1;i<=50;i++)
    {
        for (int j=1;j<=i;j++)
            f[j][1][i]=1;
        for (int j=1;j<=n;j++)
            for (int k=2;k<=n;k++)
                for (int l=1;l<=min(i,j);l++)
                    f[j][k][i]+=f[j-l][k-1][i];
    }
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,K,m;
        scanf("%d%d%d",&n,&K,&m);
        static int id=0;
        printf("Case %d: %lld\n",++id,f[n][K][m]);
    }
    return(0);
}

