#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int c[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char a[60][60],color[2510];
int to[60][60],minx[2510],maxx[2510],miny[2510],maxy[2510],f[2510][4][2];
void dfs(int x0,int y0,int value)
{
    to[x0][y0]=value;
    minx[value]=min(minx[value],x0);
    miny[value]=min(miny[value],y0);
    maxx[value]=max(maxx[value],x0);
    maxy[value]=max(maxy[value],y0);
    for (int i=0;i<4;i++)
    {
        int x=x0+c[i][0],y=y0+c[i][1];
        if (to[x][y]==0 && a[x][y]==a[x0][y0])
            dfs(x,y,value);
    }
}
int calc(int x,int y,int z)
{
    int x1=minx[x],x2=maxx[x],y1=miny[x],y2=maxy[x];
    if (y==0)
        return(z==0?to[x1][y2+1]:to[x2][y2+1]);
    else if (y==1)
        return(z==0?to[x2+1][y2]:to[x2+1][y1]);
    else if (y==2)
        return(z==0?to[x2][y1-1]:to[x1][y1-1]);
    else
        return(z==0?to[x1-1][y1]:to[x1-1][y2]);
}
int main()
{
    int n,K;
    scanf("%d%d",&n,&K);
    for (int i=1;i<=n;i++)
        scanf("%s",a[i]+1);
    int m=strlen(a[1]+1),tot=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[i][j]!='0' && to[i][j]==0)
            {
                tot++;
                color[tot]=a[i][j];
                minx[tot]=miny[tot]=1<<30;
                maxx[tot]=maxy[tot]=0;
                dfs(i,j,tot);
            }
    for (int i=1;i<=tot;i++)
        for (int j=0;j<4;j++)
            for (int k=0;k<2;k++)
                f[i][j][k]=calc(i,j,k);
    int bp=1,dp=0,cp=0;
    for (int i=1;i<=K;i++)
    {
        int p=f[bp][dp][cp];
        if (p==0)
            if (cp==0)
                cp=1;
            else
            {
                cp=0;
                dp=dp+1&3;
            }
        else
            bp=p;
    }
    printf("%c\n",color[bp]);
    return(0);
}

