#include <cstdio>
#include <cstring>
const int c[5][2]={{-1,0},{1,0},{0,-1},{0,1},{0,0}};
int a[20][20],b[20][20],ans[20][20];
void work(int x0,int y0)
{
    ans[x0][y0]=1;
    for (int i=0;i<5;i++)
    {
        int x=x0+c[i][0],y=y0+c[i][1];
        b[x][y]^=1;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        for (int i=1;i<=10;i++)
            for (int j=1;j<=10;j++)
                scanf("%d",&a[i][j]);
        for (int i=0;i<1024;i++)
        {
            memset(b,0,sizeof(b));
            memset(ans,0,sizeof(ans));
            for (int j=1;j<=10;j++)
                if (i>>j-1&1)
                    work(1,j);
            for (int j=1;j<10;j++)
                for (int k=1;k<=10;k++)
                    if (a[j][k]!=b[j][k])
                        work(j+1,k);
            bool flag=true;
            for (int j=1;j<=10;j++)
                if (a[10][j]!=b[10][j])
                {
                    flag=false;
                    break;
                }
            if (flag)
                break;
        }
        for (int i=1;i<=10;i++)
            for (int j=1;j<=10;j++)
                printf("%d%c",ans[i][j],j==10?'\n':' ');
    }
    return(0);
}

