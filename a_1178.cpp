#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int C[4]={1,0,3,2};
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool a[40][40][4];
int limit,inf,n,m,d[40][40],f[40][40],g[40][40],q[1610][2],Q[1610][2];
void bfs(int Sx,int Sy)
{
    memset(d,63,sizeof(d));
    d[Sx][Sy]=0;
    int l,r;
    l=r=1;
    q[1][0]=Sx;
    q[1][1]=Sy;
    while (l<=r)
    {
        int x0=q[l][0],y0=q[l++][1];
        for (int i=0;i<4;i++)
        {
            if (!a[x0][y0][i])
                continue;
            int x=x0+c[i][0],y=y0+c[i][1];
            if (d[x][y]!=inf)
                continue;
            d[x][y]=d[x0][y0]+1;
            q[++r][0]=x,q[r][1]=y;
        }
    }
    limit=r;
}
void calc()
{
    for (int i=limit;i;i--)
    {
        int x0=Q[i][0],y0=Q[i][1],now=0;
        for (int j=0;j<4;j++)
        {
            if (!a[x0][y0][j])
                continue;
            int x=x0+c[j][0],y=y0+c[j][1];
            a[x0][y0][j]=a[x][y][C[j]]=false;
            int tmp=inf;
            for (int k=0;k<4;k++)
            {
                if (!a[x0][y0][k] || j==k)
                    continue;
                bfs(x0+c[k][0],y0+c[k][1]);
                tmp=min(tmp,d[n][m]+1);
            }
            now=max(now,tmp);
            a[x0][y0][j]=a[x][y][C[j]]=true;
        }
        g[x0][y0]=now;
    }
    g[n][m]=0;
}
bool vis[40][40];
void spfa()
{
    int l,r;
    l=0,r=1;
    q[1][0]=n,q[1][1]=m;
    f[n][m]=0;
    vis[n][m]=true;
    while (l!=r)
    {
        l=l==1605?1:l+1;
        int x0=q[l][0],y0=q[l][1];
        vis[x0][y0]=false;
        for (int i=0;i<4;i++)
        {
            if (!a[x0][y0][i])
                continue;
            int x=x0+c[i][0],y=y0+c[i][1];
            if (max(g[x][y],f[x0][y0]+1)<f[x][y])
            {
                f[x][y]=max(g[x][y],f[x0][y0]+1);
                if (!vis[x][y])
                {
                    vis[x][y]=true;
                    r=r==1605?1:r+1;
                    q[r][0]=x,q[r][1]=y;
                }
            }
        }
    }
}
int main()
{
    while (1)
    {
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        memset(a,0,sizeof(a));
        for (int i=1;i<n;i++)
        {
            for (int j=1;j<m;j++)
            {
                int x;
                scanf("%d",&x);
                a[i][j][3]=a[i][j+1][2]=x==0;
            }
            for (int j=1;j<=m;j++)
            {
                int x;
                scanf("%d",&x);
                a[i][j][1]=a[i+1][j][0]=x==0;
            }
        }
        for (int i=1;i<m;i++)
        {
            int x;
            scanf("%d",&x);
            a[n][i][3]=a[n][i+1][2]=x==0;
        }
        memset(f,63,sizeof(f));
        inf=f[0][0];
        bfs(1,1);
        memcpy(Q,q,sizeof(q));
        calc();
        spfa();
        if (f[1][1]==inf)
            f[1][1]=-1;
        printf("%d\n",f[1][1]);
    }
    return(0);
}

