#include <cstdio>
#include <cstring>
const int N=2010,c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int d[N][N],q[N*N][2];
bool vis[N][N],T[N][N];
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        int l=1,r=0;
        memset(vis,0,sizeof(vis));
        for (int i=1;i<=n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            d[x][y]=0;
            vis[x][y]=true;
            q[r++][0]=x,q[r][1]=y;
        }
        memset(T,0,sizeof(T));
        int m;
        scanf("%d",&m);
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            T[x][y]=true;
        }
        int ans;
        while (l<=r)
        {
            int x0=q[l][0],y0=q[l++][1];
            for (int i=0;i<4;i++)
            {
                int x=x0+c[i][0],y=y0+c[i][1];
                if (x>=0 && x<=2000 && y>=0 && y<=2000 && !vis[x][y])
                {
                    vis[x][y]=true;
                    d[x][y]=d[x0][y0]+1;
                    q[++r][0]=x,q[r][1]=y;
                    if (T[x][y])
                    {
                        ans=d[x][y];
                        goto out;
                    }
                }
            }
        }
out:
        printf("%d\n",ans);
    }
    return(0);
}

