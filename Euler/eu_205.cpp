#include <cstdio>
double f[10][40],g[10][40];
int main()
{
    f[0][0]=1;
    for (int i=0;i<9;i++)
        for (int j=0;j<=36;j++)
        {
            if (f[i][j]==0)
                continue;
            for (int k=1;k<=4;k++)
                f[i+1][j+k]+=f[i][j]/4;
        }
    g[0][0]=1;
    for (int i=0;i<6;i++)
        for (int j=0;j<=36;j++)
        {
            if (g[i][j]==0)
                continue;
            for (int k=1;k<=6;k++)
                g[i+1][j+k]+=g[i][j]/6;
        }
    double ans=0;
    for (int i=0;i<=36;i++)
        for (int j=0;j<i;j++)
            ans+=f[9][i]*g[6][j];
    printf("%.7f\n",ans);
    return(0);
}

