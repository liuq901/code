#pragma comment(linker,"/STACK:12777216")
#include <cstdio>
#include <cstring>
#include <cctype>
#include <utility>
using namespace std;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
pair <int,int> pos[210][210][4];
int n,m,tot,idx,lq[210][210][4],key[210][210][4],vis[210][210][4];
bool exit[210][210][4];
char a[210][210];
int change(char ch,int dir)
{
    if (ch=='U')
        return(0);
    if (ch=='D')
        return(1);
    if (ch=='L')
        return(2);
    if (ch=='R')
        return(3);
    return(dir);
}
void dfs(int x0,int y0,int dir)
{
    vis[x0][y0][dir]=idx;
    int now=change(a[x0][y0],dir);
    int x=x0+c[now][0],y=y0+c[now][1],tmp=isdigit(a[x0][y0])?1<<a[x0][y0]-'0':0;
    key[x0][y0][dir]|=tmp;
    exit[x0][y0][dir]|=a[x0][y0]=='E';
    if (exit[x0][y0][dir])
        lq[x0][y0][dir]|=pos[x0][y0][dir].first==-2?key[x0][y0][dir]:tmp;
    if (x==0 || x>n || y==0 || y>m)
        pos[x0][y0][dir]=make_pair(-1,-1);
    else if (a[x][y]=='#')
        pos[x0][y0][dir]=make_pair(x0,y0);
    else
    {
        bool flag=false;
        if (!vis[x][y][now])
        {
            flag=true;
            dfs(x,y,now);
        }
        key[x0][y0][dir]|=key[x][y][now];
        exit[x0][y0][dir]|=exit[x][y][now];
        lq[x0][y0][dir]|=lq[x][y][now];
        if (vis[x][y][now]==idx && !flag)
            pos[x0][y0][dir]=make_pair(-2,-2);
        else
            pos[x0][y0][dir]=pos[x][y][now];
    }
}
void init()
{
    tot=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            if (a[i][j]=='K')
                a[i][j]='0'+tot++;
        }
    memset(key,0,sizeof(key));
    memset(exit,0,sizeof(exit));
    memset(lq,0,sizeof(lq));
    memset(vis,0,sizeof(vis));
    idx=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            for (int k=0;k<4;k++)
                if (!vis[i][j][k])
                {
                    idx++;
                    dfs(i,j,k);
                }
    memset(vis,0,sizeof(vis));
    idx=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            for (int k=0;k<4;k++)
                if (!vis[i][j][k])
                {
                    idx++;
                    dfs(i,j,k);
                }
}
unsigned char q[5120010][3];
short d[210][210][130];
int bfs()
{
    int Sx,Sy;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[i][j]=='S')
                Sx=i,Sy=j;
    int l,r,limit=(1<<tot)-1;
    q[l=r=1][0]=Sx,q[1][1]=Sy,q[1][2]=0;
    memset(d,-1,sizeof(d));
    d[Sx][Sy][0]=0;
    while (l<=r)
    {
        int x0=q[l][0],y0=q[l][1],now=q[l++][2];
        for (int i=0;i<4;i++)
        {
            if ((now|lq[x0][y0][i])==limit && exit[x0][y0][i])
                return(d[x0][y0][now]+1);
            int x=pos[x0][y0][i].first,y=pos[x0][y0][i].second;
            if (x<0 && y<0)
                continue;
            if (d[x][y][now|key[x0][y0][i]]==-1)
            {
                d[x][y][now|key[x0][y0][i]]=d[x0][y0][now]+1;
                q[++r][0]=x,q[r][1]=y,q[r][2]=now|key[x0][y0][i];
            }
        }
    }
    return(-1);
}
int main()
{
    while (scanf("%d%d",&n,&m)==2)
    {
        for (int i=1;i<=n;i++)
            scanf("%s",a[i]+1);
        init();
        printf("%d\n",bfs());
    }
    return(0);
}

