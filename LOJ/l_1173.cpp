#include <cstdio>
typedef unsigned long long ull;
ull f[60][60][2];
void init()
{
    const int n=50;
    f[1][1][0]=f[1][1][1]=1;
    for (int i=2;i<=n;i++)
        for (int j=1;j<=i;j++)
        {
            for (int k=j;k<i;k++)
                f[i][j][0]+=f[i-1][k][1];
            for (int k=1;k<j;k++)
                f[i][j][1]+=f[i-1][k][0];
        }
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
        if (m>1)
        {
            ull ans=0;
            for (int i=1;i<m;i++)
                ans+=f[n-1][i][0];
            printf("%llu\n",ans);
        }
        else if (n<=2)
            printf("1\n");
        else
            printf("%llu\n",f[n-1][2][1]);
    }
    return(0);
}

