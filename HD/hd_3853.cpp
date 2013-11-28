#include <cstdio>
#include <cstring>
const double eps=1e-8;
bool vis[1010][1010];
double f[1010][1010],p[1010][1010][3];
int n,m;
inline int sign(double x)
{
    return(x<-eps?-1:x>eps);
}
double solve(int x,int y)
{
    if (x>n || y>m)
        return(0);
    if (vis[x][y])
        return(f[x][y]);
    vis[x][y]=true;
    if (sign(1-p[x][y][0])==0)
        f[x][y]=1e10;
    else
        f[x][y]=(solve(x,y+1)*p[x][y][1]+solve(x+1,y)*p[x][y][2]+1)/(1-p[x][y][0]);
    return(f[x][y]);
}
int main()
{
    while (scanf("%d%d",&n,&m)==2)
    {
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                for (int k=0;k<3;k++)
                    scanf("%lf",&p[i][j][k]);
        memset(vis,0,sizeof(vis));
        vis[n][m]=true;
        f[n][m]=0;
        printf("%.3f\n",solve(1,1)*2);
    }
    return(0);
}

