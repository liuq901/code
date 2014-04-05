#include <cstdio>
#include <cstring>
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool vis[30][30];
char a[30][30];
int q[410][2];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,Sx,Sy;
        scanf("%d%d",&m,&n);
        for (int i=1;i<=n;i++)
        {
            scanf("%s",a[i]+1);
            for (int j=1;j<=m;j++)
                if (a[i][j]=='@')
                    Sx=i,Sy=j;
        }
        int l,r;
        q[l=r=1][0]=Sx,q[1][1]=Sy;
        memset(vis,0,sizeof(vis));
        vis[Sx][Sy]=true;
        while (l<=r)
        {
            int x0=q[l][0],y0=q[l++][1];
            for (int i=0;i<4;i++)
            {
                int x=x0+c[i][0],y=y0+c[i][1];
                if (x>=1 && x<=n && y>=1 && y<=m && a[x][y]=='.' && !vis[x][y])
                {
                    vis[x][y]=true;
                    q[++r][0]=x,q[r][1]=y;
                }
            }
        }
        static int id=0;
        printf("Case %d: %d\n",++id,r);
    }
    return(0);
}

