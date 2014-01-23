#include <cstdio>
typedef long long ll;
ll ans[20][1010],f[20][110][1010];
int main()
{
    f[0][0][0]=1;
    f[1][0][0]=1;
    for (int i=1;i<=10;i++)
        for (int j=0;j<=1000;j++)
            for (int k=0;k<=100;k++)
                for (int l=k+1;l<=100;l++)
                {
                    if (j+l>1000)
                        break;
                    f[i][l][j+l]+=f[i-1][k][j];
                }
    for (int i=1;i<=10;i++)
        for (int j=0;j<=1000;j++)
            for (int k=0;k<=100;k++)
                ans[i][j]+=f[i][k][j];
    while (1)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if (a==0 && b==0)
            break;
        printf("%lld\n",ans[a][b]);
    }
    return(0);
}

