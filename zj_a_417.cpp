#include <cstdio>
#include <cstring>
const int c[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int ans[110][110];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        m--;
        int p=m?-1:1;
        memset(ans,0,sizeof(ans));
        int x0=1,y0=1;
        for (int i=1;i<=n*n;i++)
        {
            ans[x0][y0]=i;
            int x=x0+c[m][0],y=y0+c[m][1];
            if (i!=n*n && (x==0 || x>n || y==0 || y>n || ans[x][y]))
            {
                m=m+p+4&3;
                i--;
            }
            else
                x0=x,y0=y;
        }
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
                printf("%5d",ans[i][j]);
            printf("\n");
        }
        printf("\n");
    }
    return(0);
}

