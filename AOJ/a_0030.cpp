#include <cstdio>
const int n=100;
int ans[100][100],f[100][100][100];
void init()
{
    int n=100;
    for (int i=0;i<10;i++)
        f[i][1][i]=1;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            for (int k=0;k<=i;k++)
                for (int p=k+1;p<10;p++)
                {
                    if (i+p>=n)
                        break;
                    f[i+p][j+1][p]+=f[i][j][k];
                }
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            for (int k=0;k<=i;k++)
                ans[i][j]+=f[i][j][k];
}
int main()
{
    init();
    while (1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        printf("%d\n",ans[m][n]);
    }
    return(0);
}

