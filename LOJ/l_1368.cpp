#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <vector>
using namespace std;
const double pi=acos(-1.0),cir=pi/4,squ=4-2*cir;
vector <pair <int,int> > a[210][210];
int idx,vis[210][210];
double ans[40010],area[210][210];
char buf[110];
void add(int x0,int y0,int x1,int y1)
{
    a[x0][y0].push_back(make_pair(x1,y1));
    a[x1][y1].push_back(make_pair(x0,y0));
}
double dfs(int x0,int y0)
{
    vis[x0][y0]=idx;
    double ret=area[x0][y0];
    for (int i=0;i<a[x0][y0].size();i++)
    {
        int x=a[x0][y0][i].first,y=a[x0][y0][i].second;
        if (!vis[x][y])
            ret+=dfs(x,y);
    }
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=0;i<=2*n;i++)
            for (int j=0;j<=2*m;j++)
                a[i][j].clear();
        memset(area,0,sizeof(area));
        for (int i=1;i<=n;i++)
        {
            scanf("%s",buf+1);
            for (int j=1;j<=m;j++)
            {
                area[2*i-1][2*j-1]+=squ;
                if (buf[j]=='0')
                {
                    area[2*i-2][2*j-2]+=cir;
                    area[2*i][2*j]+=cir;
                    add(2*i-1,2*j-1,2*i-2,2*j);
                    add(2*i-1,2*j-1,2*i,2*j-2);
                }
                else
                {
                    area[2*i-2][2*j]+=cir;
                    area[2*i][2*j-2]+=cir;
                    add(2*i-1,2*j-1,2*i-2,2*j-2);
                    add(2*i-1,2*j-1,2*i,2*j);
                }
            }
        }
        memset(vis,0,sizeof(vis));
        idx=0;
        static int id=0;
        printf("Case %d:\n",++id);
        int Q;
        scanf("%d",&Q);
        while (Q--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if (!vis[x][y])
            {
                idx++;
                ans[idx]=dfs(x,y);
            }
            printf("%.10f\n",ans[vis[x][y]]);
        }
    }
    return(0);
}

