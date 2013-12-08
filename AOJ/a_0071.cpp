#include <cstdio>
#include <cstring>
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char a[10][10];
bool vis[10][10];
int q[100][2];
void bfs(int Sx,int Sy)
{
    memset(vis,0,sizeof(vis));
    int l,r;
    q[l=r=1][0]=Sx,q[1][1]=Sy;
    vis[Sx][Sy]=true;
    while (l<=r)
    {
        int x0=q[l][0],y0=q[l++][1];
        a[x0][y0]='0';
        for (int i=0;i<4;i++)
            for (int j=1;j<=3;j++)
            {
                int x=x0+c[i][0]*j,y=y0+c[i][1]*j;
                if (x>=1 && x<=8 && y>=1 && y<=8 && !vis[x][y] && a[x][y]=='1')
                {
                    vis[x][y]=true;
                    q[++r][0]=x,q[r][1]=y;
                }
            }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        for (int i=1;i<=8;i++)
            scanf("%s",a[i]+1);
        int Sx,Sy;
        scanf("%d%d",&Sy,&Sx);
        bfs(Sx,Sy);
        static int id=0;
        printf("Data %d:\n",++id);
        for (int i=1;i<=8;i++)
            printf("%s\n",a[i]+1);
    }
    return(0);
}

