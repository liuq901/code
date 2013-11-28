#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>
using namespace std;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
queue <pair <int,int> > q;
int d[130][130],a[130][130];
bool in[130][130];
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                scanf("%d",&a[i][j]);
        memset(d,63,sizeof(d));
        d[1][1]=a[1][1];
        q.push(make_pair(1,1));
        in[1][1]=true;
        while (!q.empty())
        {
            int x0=q.front().first,y0=q.front().second;
            q.pop();
            in[x0][y0]=false;
            for (int i=0;i<4;i++)
            {
                int x=x0+c[i][0],y=y0+c[i][1];
                if (x>0 && x<=n && y>0 && y<=n && d[x0][y0]+a[x][y]<d[x][y])
                {
                    d[x][y]=d[x0][y0]+a[x][y];
                    if (!in[x][y])
                    {
                        in[x][y]=true;
                        q.push(make_pair(x,y));
                    }
                }
            }
        }
        static int id=0;
        printf("Problem %d: %d\n",++id,d[n][n]);
    }
    return(0);
}

