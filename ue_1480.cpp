#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>
using namespace std;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool a[260][260];
int d[260][260];
queue <pair <int,int> > Q;
int bfs(int n,int m)
{
    memset(d,-1,sizeof(d));
    if (!a[1][1])
    {
        d[1][1]=0;
        Q.push(make_pair(1,1));
    }
    while (!Q.empty())
    {
        int x0=Q.front().first,y0=Q.front().second;
        Q.pop();
        for (int i=0;i<4;i++)
        {
            int x=x0+c[i][0],y=y0+c[i][1];
            if (x>=1 && x<=n && y>=1 && y<=m && !a[x][y] && d[x][y]==-1)
            {
                d[x][y]=d[x0][y0]+1;
                Q.push(make_pair(x,y));
            }
        }
    }
    return(d[n][m]);
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
            for (int j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
        static int id=0;
        printf("Case #%d: %d\n",++id,bfs(n,m));
    }
    return(0);
}

