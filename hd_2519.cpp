#include <cstdio>
int c[40][40];
int main()
{
    for (int i=1;i<=30;i++)
    {
        c[i][0]=c[i][i]=1;
        for (int j=1;j<i;j++)
            c[i][j]=c[i-1][j-1]+c[i-1][j];
    }
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        printf("%d\n",c[n][m]);
    }
    return(0);
}

