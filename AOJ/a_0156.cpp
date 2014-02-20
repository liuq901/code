#include <cstdio>
#include <cstring>
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char a[110][110];
int d[110][110],q[20010][2];
int main()
{
    while (1)
    {
        int n,m;
        scanf("%d%d",&m,&n);
        if (n==0 && m==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%s",a[i]+1);
        memset(d,63,sizeof(d));
        int l,r;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                if (a[i][j]=='&')
                {
                    q[l=r=10000][0]=i;
                    q[10000][1]=j;
                    d[i][j]=0;
                    a[i][j]='.';
                    goto out;
                }
out:
        while (l<=r)
        {
            int x0=q[l][0],y0=q[l++][1];
            for (int i=0;i<4;i++)
            {
                int x=x0+c[i][0],y=y0+c[i][1];
                if (x<=0 || x>n || y<=0 || y>m)
                {
                    printf("%d\n",d[x0][y0]);
                    goto final;
                }
                if ((a[x][y]==a[x0][y0] || a[x][y]=='.') && d[x0][y0]<d[x][y])
                {
                    d[x][y]=d[x0][y0];
                    q[--l][0]=x;
                    q[l][1]=y;
                }
                if (a[x][y]=='#' && a[x0][y0]=='.' && d[x0][y0]+1<d[x][y])
                {
                    d[x][y]=d[x0][y0]+1;
                    q[++r][0]=x;
                    q[r][1]=y;
                }
            }
        }
final:
        ;
    }
    return(0);
}

