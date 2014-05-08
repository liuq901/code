#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll p[30],f[30][160];
void init()
{
    int n=24,m=150;
    p[0]=1;
    for (int i=1;i<=24;i++)
        p[i]=p[i-1]*6;
    f[0][0]=1;
    for (int i=1;i<=n;i++)
        for (int j=0;j<=m;j++)
            for (int k=1;k<=6;k++)
                f[i][j+k]+=f[i-1][j];
    for (int i=1;i<=n;i++)
        for (int j=m;j>=0;j--)
            f[i][j]+=f[i][j+1];
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        static int id=0;
        printf("Case %d: ",++id);
        if (f[n][m]==0)
            printf("0\n");
        else if (f[n][m]==p[n])
            printf("1\n");
        else
        {
            ll tmp=__gcd(f[n][m],p[n]);
            printf("%lld/%lld\n",f[n][m]/tmp,p[n]/tmp);
        }
    }
    return(0);
}

