#include <cstdio>
const int N=1010;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int l,r,n,m,cnt,d[N][N],dis[N][N],vis[N][N],q[N*N][2];
void bfs(int limit)
{
    while (l<=r)
    {
        int x0=q[l][0],y0=q[l++][1];
        for (int i=0;i<4;i++)
        {
            int x=x0+c[i][0],y=y0+c[i][1];
            if (x<0 || x==n || y<0 || y==m || vis[x][y]==cnt || dis[x][y]<limit)
                continue;
            vis[x][y]=cnt;
            d[x][y]=d[x0][y0]+1;
            q[++r][0]=x,q[r][1]=y;
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int N,Sx,Sy,Tx,Ty;
        scanf("%d%d%d%d%d%d%d",&N,&n,&m,&Sx,&Sy,&Tx,&Ty);
        cnt++;
        l=1,r=0;
        for (int i=1;i<=N;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            vis[x][y]=cnt;
            d[x][y]=0;
            q[++r][0]=x,q[r][1]=y;
        }
        bfs(-1);
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                dis[i][j]=d[i][j];
        int lo=0,hi=dis[Sx][Sy],ans0,ans1;
        while (lo<=hi)
        {
            int mid=lo+hi>>1;
            cnt++;
            vis[Sx][Sy]=cnt;
            d[Sx][Sy]=0;
            q[l=r=1][0]=Sx,q[1][1]=Sy;
            bfs(mid);
            if (vis[Tx][Ty]==cnt)
            {
                ans0=mid,ans1=d[Tx][Ty];
                lo=mid+1;
            }
            else
                hi=mid-1;
        }
        printf("%d %d\n",ans0,ans1);
    }
    return(0);
}

