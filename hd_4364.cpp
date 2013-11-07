#include <cstdio>
#include <cstring>
const int n=4;
const int c[5][5]={{0},{0,2,3,1,1},{0,1,2,3,1},{0,1,1,2,3},{0,3,1,1,2}};
int a[5][5],b[5][5];
int calc(int x,int y)
{
    if (x==1)
        return(y);
    if (x==2)
    {
        y<<=1;
        if (y>0xff)
            y^=0x1b;
        return(y);
    }
    if (x==3)
    {
        int z=y<<1;
        if (z>0xff)
            z^=0x1b;
        return(y^z);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                scanf("%X",&a[i][j]);
        memset(b,0,sizeof(b));
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                for (int k=1;k<=n;k++)
                    b[i][j]^=calc(c[i][k],a[k][j]);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                printf("%02X%c",b[i][j]&255,j==n?'\n':' ');
        if (T)
            printf("\n");
    }
    return(0);
}

