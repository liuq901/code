#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
struct state
{
    int x,y,k;
    state(int x,int y,int k):x(x),y(y),k(k){}
};
int n,d[30][30],tmp[4][30][30],f[30][30][4],b[30][30][4][4];
char a[30][30];
bool vis[30][30][4],in[30][30][4];
queue <state> Q;
inline bool check(int x,int y)
{
    return(x>=1 && x<=n && y>=1 && y<=n && a[x][y]!='#');
}
inline bool update(int &a,int b)
{
    if (a==-1 || b<a)
    {
        a=b;
        return(true);
    }
    return(false);
}
int q[1000][2];
void bfs(int X,int Y,int Sx,int Sy)
{
    memset(d,-1,sizeof(d));
    d[Sx][Sy]=0;
    int l=1,r=1;
    q[1][0]=Sx,q[1][1]=Sy;
    while (l<=r)
    {
        int x0=q[l][0],y0=q[l++][1];
        for (int i=0;i<4;i++)
        {
            int x=x0+c[i][0],y=y0+c[i][1];
            if (check(x,y) && (x!=X || y!=Y) && d[x][y]==-1)
            {
                d[x][y]=d[x0][y0]+1;
                q[++r][0]=x,q[r][1]=y;
            }
        }
    }
}
void spfa()
{
    while (!Q.empty())
    {
        int x0=Q.front().x,y0=Q.front().y,k=Q.front().k;
        Q.pop();
        in[x0][y0][k]=false;
        if (!vis[x0][y0][k])
        {
            vis[x0][y0][k]=true;
            bfs(x0,y0,x0+c[k][0],y0+c[k][1]);
            for (int i=0;i<4;i++)
            {
                int x=x0+c[i][0],y=y0+c[i][1];
                if (check(x,y))
                    b[x0][y0][k][i]=d[x][y];
                else
                    b[x0][y0][k][i]=-1;
            }
        }
        for (int i=0;i<4;i++)
            if (b[x0][y0][k][i]!=-1 && update(f[x0][y0][i],f[x0][y0][k]+b[x0][y0][k][i]) && !in[x0][y0][i])
            {
                in[x0][y0][i]=true;
                Q.push(state(x0,y0,i));
            }
        int x=x0+c[k][0],y=y0+c[k][1];
        if (check(x+c[k][0],y+c[k][1]) && update(f[x][y][k],f[x0][y0][k]+1) && !in[x][y][k])
        {
            in[x][y][k]=true;
            Q.push(state(x,y,k));
        }
    }
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%s",a[i]+1);
    int Tx,Ty;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (a[i][j]=='*')
                Tx=i,Ty=j;
    memset(f,-1,sizeof(f));
    for (int i=0;i<4;i++)
    {
        int x=Tx+c[i][0],y=Ty+c[i][1];
        if (check(x,y))
        {
            f[Tx][Ty][i]=0;
            in[Tx][Ty][i]=true;
            Q.push(state(Tx,Ty,i));
        }
    }
    spfa();
    int ans=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            if (i==Tx && j==Ty)
                continue;
            for (int k=0;k<4;k++)
            {
                if (f[i][j][k]==-1)
                    continue;
                int x0=i+c[k][0],y0=j+c[k][1];
                bfs(i,j,x0,y0);
                memcpy(tmp[k],d,sizeof(d));
            }
            for (int x=1;x<=n;x++)
                for (int y=1;y<=n;y++)
                {
                    int now=-1;
                    for (int k=0;k<4;k++)
                        if (f[i][j][k]!=-1 && tmp[k][x][y]!=-1)
                            update(now,f[i][j][k]+tmp[k][x][y]);
                    ans=max(ans,now);
                }
        }
    printf("%d\n",ans);
    return(0);
}

