#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
const int n=80;
int a[n+10][n+10],d[n+10][n+10];
bool vis[n+10][n+10];
queue <pair <int,int> > Q;
void spfa()
{
    while (!Q.empty())
    {
        int x0=Q.front().first,y0=Q.front().second;
        vis[x0][y0]=false;
        Q.pop();
        for (int i=0;i<4;i++)
        {
            int x=x0+c[i][0],y=y0+c[i][1];
            if (x>0 && x<=n && y>0 && y<=n && d[x0][y0]+a[x][y]<d[x][y])
            {
                d[x][y]=d[x0][y0]+a[x][y];
                if (!vis[x][y])
                {
                    vis[x][y]=true;
                    Q.push(make_pair(x,y));
                }
            }
        }
    }
}
int main()
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            scanf("%d%*c",&a[i][j]);
    memset(d,63,sizeof(d));
    Q.push(make_pair(1,1));
    d[1][1]=a[1][1];
    vis[1][1]=true;
    spfa();
    printf("%d\n",d[n][n]);
    return(0);
}

