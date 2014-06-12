#include <cstdio>
#include <cstring>
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char a[210][210];
int d[210][210],p[210][210],q[40010][3];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            scanf("%s",a[i]+1);
        int Sx,Sy,Tx,Ty;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                if (a[i][j]=='P')
                    Sx=i,Sy=j;
                if (a[i][j]=='D')
                    Tx=i,Ty=j;
            }
        memset(d,-1,sizeof(d));
        memset(p,-1,sizeof(p));
        d[Sx][Sy]=0;
        int l,r,px=-1,py=-1;
        q[l=r=1][0]=Sx,q[1][1]=Sy,q[1][2]=0;
        while (l<=r)
        {
            int x0=q[l][0],y0=q[l][1],state=q[l++][2];
            if (state)
            {
                if (px==0)
                    continue;
                if (px!=-1)
                {
                    d[px][py]=p[x0][y0]+1;
                    q[++r][0]=px,q[r][1]=py,q[r][2]=0;
                    px=py=0;
                    continue;
                }
                for (int i=1;i<=n;i++)
                    for (int j=1;j<=m;j++)
                        if (a[i][j]=='*' && (i!=x0 || j!=y0))
                        {
                            d[i][j]=p[x0][y0]+1;
                            q[++r][0]=i,q[r][1]=j,q[r][2]=0;
                        }
                px=x0;
                py=y0;
                continue;
            }
            if (a[x0][y0]=='*' && px>0 && d[px][py]==-1)
            {
                d[px][py]=d[x0][y0]+1;
                q[++r][0]=px,q[r][1]=py;
                px=py=0;
            }
            for (int i=0;i<4;i++)
            {
                int x=x0+c[i][0],y=y0+c[i][1];
                if (a[x][y]=='#')
                    continue;
                if (a[x][y]=='*')
                {
                    if (p[x][y]!=-1)
                        continue;
                    p[x][y]=d[x0][y0]+1;
                    q[++r][0]=x,q[r][1]=y,q[r][2]=1;
                }
                else if (d[x][y]==-1)
                {
                    d[x][y]=d[x0][y0]+1;
                    q[++r][0]=x,q[r][1]=y,q[r][2]=0;
                }
            }
        }
        static int id=0;
        printf("Case %d: ",++id);
        if (d[Tx][Ty]==-1)
            printf("impossible\n");
        else
            printf("%d\n",d[Tx][Ty]);
    }
    return(0);
}

