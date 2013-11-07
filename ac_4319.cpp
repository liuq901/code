#include <cstdio>
#include <cstring>
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
const int Q=200000;
char a[30][30];
bool vis[30][30],in[30][30][410];
int layer[30][30],d[30][30][410],q[Q+10][3];
inline bool move(int x,int y,int dx,int dy,int n,int m,int D)
{
    for (int i=1;i<=D;i++)
    {
        x+=dx,y+=dy;
        if (!x || x>n || !y || y>m || a[x][y]!=' ')
            return(false);
    }
    return(true);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        gets(a[0]);
        for (int i=1;i<=n;i++)
            gets(a[i]+1);
        int Sx,Sy,Tx,Ty;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                if (a[i][j]=='S')
                {
                    Sx=i,Sy=j;
                    a[i][j]=' ';
                }
                if (a[i][j]=='E')
                {
                    Tx=i,Ty=j;
                    a[i][j]=' ';
                }
            }
        memset(layer,63,sizeof(layer));
        layer[Sx][Sy]=0;
        vis[Sx][Sy]=true;
        q[1][0]=Sx,q[1][1]=Sy;
        int l=0,r=1;
        while (l!=r)
        {
            l=l==Q?1:l+1;
            int x0=q[l][0],y0=q[l][1];
            vis[x0][y0]=false;
            for (int i=0;i<4;i++)
            {
                int x=x0+c[i][0],y=y0+c[i][1];
                if (!x || x>n || !y || y>m || a[x][y]=='#')
                    continue;
                int value=a[x][y]=='*';
                if (layer[x0][y0]+value<layer[x][y])
                {
                    layer[x][y]=layer[x0][y0]+value;
                    if (!vis[x][y])
                    {
                        vis[x][y]=true;
                        r=r==Q?1:r+1;
                        q[r][0]=x,q[r][1]=y;
                    }
                }
            }
        }
        int D,K,tmp;
        scanf("%d%d%d",&D,&K,&tmp);
        K/=tmp;
        if (layer[Tx][Ty]>K)
        {
            printf("can not reach!\n");
            continue;
        }
        K-=layer[Tx][Ty];
        memset(d,63,sizeof(d));
        d[Sx][Sy][0]=0;
        in[Sx][Sy][0]=true;
        q[1][0]=Sx,q[1][1]=Sy,q[1][2]=0;
        l=0,r=1;
        int ansA=1<<30,ansB;
        while (l!=r)
        {
            l=l==Q?1:l+1;
            int x0=q[l][0],y0=q[l][1],k=q[l][2];
            if (x0==Tx && y0==Ty)
            {
                if (d[x0][y0][k]<ansA)
                {
                    ansA=d[x0][y0][k];
                    ansB=0;
                }
                if (d[x0][y0][k]==ansA && k>ansB)
                    ansB=k;
            }
            in[x0][y0][k]=false;
            for (int i=0;i<4;i++)
            {
                int x=x0+c[i][0],y=y0+c[i][1];
                if (!x || x>n || !y || y>m || a[x][y]=='#')
                    continue;
                int value=a[x][y]=='*';
                if (layer[x][y]!=layer[x0][y0]+value)
                    continue;
                if (d[x0][y0][k]+1<d[x][y][k])
                {
                    d[x][y][k]=d[x0][y0][k]+1;
                    if (!in[x][y][k])
                    {
                        in[x][y][k]=true;
                        r=r==Q?1:r+1;
                        q[r][0]=x,q[r][1]=y,q[r][2]=k;
                    }
                }
                if (k==K)
                    continue;
                if (move(x0,y0,c[i][0],c[i][1],n,m,D))
                {
                    x=x0+c[i][0]*D,y=y0+c[i][1]*D;
                    if (d[x0][y0][k]+D<d[x][y][k+1])
                    {
                        d[x][y][k+1]=d[x0][y0][k]+D;
                        if (!in[x][y][k+1])
                        {
                            in[x][y][k+1]=true;
                            r=r==Q?1:r+1;
                            q[r][0]=x,q[r][1]=y,q[r][2]=k+1;
                        }
                    }
                }
            }
        }
        printf("%d\n",ansA-(D-1)*ansB);
    }
    return(0);
}

