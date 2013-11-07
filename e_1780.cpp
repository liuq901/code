#include <cstdio>
#include <cstring>
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char a[100][100];
int n,m,d[100][100][4],q[40000][3];
int BFS()
{
    int Sx,Sy;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[i][j]=='@')
                Sx=i,Sy=j;
    int l,r;
    l=1,r=0;
    memset(d,-1,sizeof(d));
    for (int i=0;i<4;i++)
    {
        q[++r][0]=Sx,q[r][1]=Sy,q[r][2]=i;
        d[Sx][Sy][i]=0;
    }
    while (l<=r)
    {
        int x0=q[l][0],y0=q[l][1],dir=q[l++][2],cnt=0;
        for (int i=0;i<4;i++)
        {
            int x=x0+c[i][0],y=y0+c[i][1];
            if (x==0 || x>n || y==0 || y>m)
                return(d[x0][y0][dir]);
        }
        for (int i=0;i<4;i++)
        {
            if ((i^dir)==1 || i==dir)
                continue;
            int x=x0+c[i][0],y=y0+c[i][1];
            if (a[x][y]=='.')
            {
                cnt++;
                if (d[x][y][i]==-1)
                {
                    d[x][y][i]=d[x0][y0][dir]+1;
                    q[++r][0]=x,q[r][1]=y,q[r][2]=i;
                }
            }
        }
        if (cnt==0)
        {
            int x=x0+c[dir][0],y=y0+c[dir][1];
            if (a[x][y]=='.' && d[x][y][dir]==-1)
            {
                d[x][y][dir]=d[x0][y0][dir]+1;
                q[++r][0]=x,q[r][1]=y,q[r][2]=dir;
            }
        }
    }
    return(-1);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            scanf("%s",a[i]+1);
        printf("%d\n",BFS());
    }
    return(0);
}

