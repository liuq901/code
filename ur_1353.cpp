#include <cstdio>
int f[20][100];
int main()
{
    f[0][0]=1;
    for (int i=1;i<10;i++)
        for (int j=0;j<=81;j++)
            for (int k=0;k<10;k++)
            {
                if (k>j)
                    break;
                f[i][j]+=f[i-1][j-k];
            }
    f[9][1]++;
    int n;
    scanf("%d",&n);
    printf("%d\n",f[9][n]);
    return(0);
}

