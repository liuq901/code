#include <cstdio>
#include <cstring>
const char c[3][10]={"INSERT","DELETE","REPLACE"};
char a[1010],b[1010],p[1010][1010];
int f[1010][1010],g[1010][1010],pre[1010][1010][2];
int print(int x,int y)
{
    if (x==0 && y==0)
        return(0);
    int pos=print(pre[x][y][0],pre[x][y][1]);
    if (g[x][y]!=-1)
    {
        printf("%s %d",c[g[x][y]],pos+1);
        if (g[x][y]!=1)
            printf(" %c",p[x][y]);
        printf("\n");
    }
    if (g[x][y]==1)
        return(pos);
    return(pos+1);
}
int main()
{
    scanf("%s%s",a+1,b+1);
    int n=strlen(a+1),m=strlen(b+1);
    for (int i=1;i<=n;i++)
    {
        f[i][0]=i;
        pre[i][0][0]=i-1;
        pre[i][0][1]=0;
        g[i][0]=1;
    }
    for (int i=1;i<=m;i++)
    {
        f[0][i]=i;
        pre[0][i][0]=0;
        pre[0][i][1]=i-1;
        g[0][i]=0;
        p[0][i]=b[i];
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            if (f[i-1][j]<f[i][j-1])
            {
                f[i][j]=f[i-1][j]+1;
                pre[i][j][0]=i-1;
                pre[i][j][1]=j;
                g[i][j]=1;
            }
            else
            {
                f[i][j]=f[i][j-1]+1;
                pre[i][j][0]=i;
                pre[i][j][1]=j-1;
                g[i][j]=0;
                p[i][j]=b[j];
            }
            if (a[i]==b[j] && f[i-1][j-1]<f[i][j])
            {
                f[i][j]=f[i-1][j-1];
                pre[i][j][0]=i-1;
                pre[i][j][1]=j-1;
                g[i][j]=-1;
            }
            if (a[i]!=b[j] && f[i-1][j-1]+1<f[i][j])
            {
                f[i][j]=f[i-1][j-1]+1;
                pre[i][j][0]=i-1;
                pre[i][j][1]=j-1;
                g[i][j]=2;
                p[i][j]=b[j];
            }
        }
    printf("%d\n",f[n][m]);
    print(n,m);
    return(0);
}

