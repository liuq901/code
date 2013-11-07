#include <cstdio>
#include <cstring>
const int c[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int d[210][210],f[210][210][4],q[1000000][2];
bool vis[210][210];
int main()
{
    while (1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n==-1 && m==-1)
            break;
        memset(f,0,sizeof(f));
        for (int i=1;i<=n;i++)
        {
            int x,y,op,d;
            scanf("%d%d%d%d",&x,&y,&op,&d);
            if (op==0)
                for (int i=0;i<d;i++)
                {
                    f[x+i][y][3]=-1;
                    f[x+i][y-1][2]=-1;
                }
            else
                for (int i=0;i<d;i++)
                {
                    f[x][y+i][1]=-1;
                    f[x-1][y+i][0]=-1;
                }
        }
        for (int i=1;i<=m;i++)
        {
            int x,y,op;
            scanf("%d%d%d",&x,&y,&op);
            if (op==0)
            {
                f[x][y][3]=1;
                f[x][y-1][2]=1;
            }
            else
            {
                f[x][y][1]=1;
                f[x-1][y][0]=1;
            }
        }
        double X,Y;
        scanf("%lf%lf",&X,&Y);
        if (X<1 || X>200 || Y<1 || Y>200)
            printf("0\n");
        else
        {
            int Sx=int(X),Sy=int(Y),l,r;
            memset(vis,0,sizeof(vis));
            memset(d,63,sizeof(d));
            l=r=1;
            q[1][0]=Sx,q[1][1]=Sy;
            vis[Sx][Sy]=true;
            d[Sx][Sy]=0;
            int noSolution=d[0][0];
            while (l<=r)
            {
                int x0=q[l][0],y0=q[l++][1];
                vis[x0][y0]=false;
                for (int i=0;i<4;i++)
                {
                    if (f[x0][y0][i]==-1)
                        continue;
                    int x=x0+c[i][0],y=y0+c[i][1];
                    if (d[x0][y0]+f[x0][y0][i]<d[x][y])
                    {
                        d[x][y]=d[x0][y0]+f[x0][y0][i];
                        if (!vis[x][y])
                        {
                            q[++r][0]=x,q[r][1]=y;
                            vis[x][y]=true;
                        }
                    }
                }
            }
            if (d[0][0]==noSolution)
                printf("-1\n");
            else
                printf("%d\n",d[0][0]);
        }
    }
    return(0);
}

