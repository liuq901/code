#include <cstdio>
#include <cstring>
#include <cctype>
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char a[1010][1010];
int n,m,d[1010][1010],q[1000010][2];
void bfs()
{
    int Sx,Sy;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[i][j]=='E')
                Sx=i,Sy=j;
    int l,r;
    q[l=r=1][0]=Sx,q[1][1]=Sy;
    memset(d,-1,sizeof(d));
    d[Sx][Sy]=0;
    while (l<=r)
    {
        int x0=q[l][0],y0=q[l++][1];
        for (int i=0;i<4;i++)
        {
            int x=x0+c[i][0],y=y0+c[i][1];
            if (x>0 && x<=n && y>0 && y<=m && a[x][y]!='T' && d[x][y]==-1)
            {
                d[x][y]=d[x0][y0]+1;
                q[++r][0]=x,q[r][1]=y;
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%s",a[i]+1);
    bfs();
    int limit;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[i][j]=='S')
                limit=d[i][j];
    int ans=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (isdigit(a[i][j]) && d[i][j]!=-1 && d[i][j]<=limit)
                ans+=a[i][j]-'0';
    printf("%d\n",ans);
    return(0);
}

