#include <cstdio>
char a[50][50];
int s[50][50],f[50][50][50],g[50][50][50],ans[50][50][50][50];
inline bool check(int x0,int y0,int x1,int y1)
{
    int sum=s[x1][y1]-s[x0-1][y1]-s[x1][y0-1]+s[x0-1][y0-1];
    return(sum==(x1-x0+1)*(y1-y0+1));
}
int main()
{
    int n,m,Q;
    scanf("%d%d%d",&n,&m,&Q);
    for (int i=1;i<=n;i++)
        scanf("%s",a[i]+1);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+(a[i][j]=='0');
    for (int x=n;x;x--)
        for (int y=m;y;y--)
        {
            for (int i=x;i<=n;i++)
                for (int j=y;j<=m;j++)
                {
                    f[y][i][j]+=check(x,y,i,j);
                    g[y][i][j]=g[y+1][i][j]+f[y][i][j];
                }
            int tmp[50]={0};
            for (int i=x;i<=n;i++)
                for (int j=y;j<=m;j++)
                {
                    tmp[j]+=g[y][i][j];
                    ans[x][y][i][j]=ans[x][y][i][j-1]+tmp[j];
                }
        }
    while (Q--)
    {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        printf("%d\n",ans[a][b][c][d]);
    }
    return(0);
}

