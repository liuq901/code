#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>
using namespace std;
const int c[8][2]={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
int pos[20][2],dis[20][20],d[30][30],cnt[30][30],f[32770][20];
char a[30][30];
void bfs(int id,int n,int m,int tot)
{
    int Sx=pos[id][0],Sy=pos[id][1];
    queue <pair <int,int> > Q;
    memset(d,-1,sizeof(d));
    d[Sx][Sy]=0;
    Q.push(make_pair(Sx,Sy));
    while (!Q.empty())
    {
        int x0=Q.front().first,y0=Q.front().second;
        Q.pop();
        for (int i=0;i<8;i++)
        {
            int x=x0+c[i][0],y=y0+c[i][1];
            if (x>0 && x<=n && y>0 && y<=m && d[x][y]==-1)
            {
                d[x][y]=d[x0][y0]+1;
                Q.push(make_pair(x,y));
            }
        }
    }
    for (int i=0;i<=tot;i++)
        dis[id][i]=d[pos[i][0]][pos[i][1]];
}
void update(int &x,int y)
{
    if (x==-1 || y<x)
        x=y;
}
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
        int tot=0,Sx,Sy;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                cnt[i][j]=-1;
                if (a[i][j]=='x')
                {
                    Sx=i,Sy=j;
                    cnt[i][j]=0;
                }
                else if (a[i][j]=='g')
                {
                    cnt[i][j]=++tot;
                    pos[tot][0]=i;
                    pos[tot][1]=j;
                }
            }
        pos[0][0]=Sx;
        pos[0][1]=Sy;
        for (int i=0;i<=tot;i++)
            bfs(i,n,m,tot);
        memset(f,-1,sizeof(f));
        f[0][0]=0;
        for (int i=0;i<1<<tot;i++)
            for (int j=0;j<=tot;j++)
            {
                if (f[i][j]==-1)
                    continue;
                for (int k=0;k<=tot;k++)
                {
                    int state=i;
                    if (k>0)
                        state|=1<<k-1;
                    update(f[state][k],f[i][j]+dis[j][k]);
                }
            }
        static int id=0;
        printf("Case %d: %d\n",++id,f[(1<<tot)-1][0]);
    }
    return(0);
}

