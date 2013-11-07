#include <cstdio>
int f[110][110];
int main()
{
    f[0][0]=1;
    for (int i=1;i<=100;i++)
        for (int j=1;j<=i;j++)
            for (int k=0;k<=j;k++)
                f[i][j]+=f[i-j][k];
    int ans=0;
    for (int i=1;i<100;i++)
        ans+=f[100][i];
    printf("%d\n",ans);
    return(0);
}

