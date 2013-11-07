#include <cstdio>
typedef long long ll;
ll ans[60],f[5][60][5];
int main()
{
    f[1][1][1]=f[2][1][2]=f[3][1][3]=1;
    ans[1]=3;
    for (int i=2;i<=50;i++)
    {
        for (int j=1;j<=3;j++)
        {
            f[j][i][1]=f[j][i-1][2]+f[j][i-1][3];
            f[j][i][2]=f[j][i-1][1]+f[j][i-1][3];
            f[j][i][3]=f[j][i-1][1]+f[j][i-1][2];
            for (int k=1;k<=3;k++)
                if (j!=k)
                    ans[i]+=f[j][i][k];
        }
    }
    int n;
    while (scanf("%d",&n)==1)
        printf("%I64d\n",ans[n]);
    return(0);
}

