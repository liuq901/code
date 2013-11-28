#include <cstdio>
#include <cstring>
#include <cctype>
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int gate[30][2],f[60][60],q[2510][2],to[60][60][2];
char a[60][60];
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
        memset(gate,0,sizeof(gate));
        memset(to,0,sizeof(to));
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                if (a[i][j]=='Q')
                    Sx=i,Sy=j;
                if (a[i][j]=='L')
                    Tx=i,Ty=j;
                if (islower(a[i][j]))
                {
                    int num=a[i][j]-'a';
                    if (gate[num][0]==0)
                        gate[num][0]=i,gate[num][1]=j;
                    else
                    {
                        to[i][j][0]=gate[num][0],to[i][j][1]=gate[num][1];
                        to[gate[num][0]][gate[num][1]][0]=i;
                        to[gate[num][0]][gate[num][1]][1]=j;
                    }
                }
            }
        memset(f,-1,sizeof(f));
        f[Sx][Sy]=0;
        int l,r;
        q[l=r=1][0]=Sx,q[1][1]=Sy;
        while (l<=r)
        {
            int x0=q[l][0],y0=q[l++][1];
            for (int i=0;i<4;i++)
            {
                int x=x0+c[i][0],y=y0+c[i][1];
                if (x==0 || x>n || y==0 || y>m || a[x][y]=='#')
                    continue;
                if (to[x][y][0]!=0)
                {
                    int u=to[x][y][0],v=to[x][y][1];
                    x=u,y=v;
                }
                if (f[x][y]==-1)
                {
                    f[x][y]=f[x0][y0]+1;
                    q[++r][0]=x,q[r][1]=y;
                }
            }
        }
        printf("%d\n",f[Tx][Ty]);
    }
    return(0);
}

