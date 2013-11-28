#include <cstdio>
int f[30][20][20][10][10];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=4;i++)
        for (int j=1;j<=4;j++)
        {
            if (i==j)
                continue;
            f[2][0][0][i][j]=1;
        }
    for (int i=2;i<n;i++)
        for (int j=0;j<=m;j++)
            for (int k=0;k<m;k++)
                for (int l=1;l<=4;l++)
                    for (int x=1;x<=4;x++)
                        for (int y=1;y<=4;y++)
                        {
                            if (x==y)
                                continue;
                            int t1,t2;
                            t1=t2=0;
                            if (l<x && y<x)
                                t1=1;
                            if (l>x && y>x)
                                t2=1;
                            f[i+1][j+t1][k+t2][x][y]+=f[i][j][k][l][x];
                        }
    int ans=0;
    for (int i=1;i<=4;i++)
        for (int j=1;j<=4;j++)
            ans+=f[n][m][m-1][i][j];
    printf("%d\n",ans);
    return(0);
}

