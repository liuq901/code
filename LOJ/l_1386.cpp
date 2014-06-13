#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int n,target[30][2],a[10][10],dis[30][10][10];
void init()
{
    const int n=5;
    int t=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=4;j++)
        {
            t++;
            target[t][0]=i;
            target[t][1]=j;
        }
    for (int k=2;k<=n*4;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=4;j++)
            {
                int dx=abs(i-target[k][0]);
                int dy=abs(j-target[k][1]);
                if (dy==3)
                    dy=1;
                dis[k][i][j]=dx+dy;
            }
}
bool check()
{
    bool vis[30]={0};
    int cnt=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=4;j++)
        {
            for (int k=2;k<a[i][j];k++)
                cnt+=!vis[k];
            vis[a[i][j]]=true;
            if (a[i][j]==1 && i%2==0)
                cnt++;
        }
    return(cnt%2==0);
}
int ans;
bool dfs(int dep,int best,int x0,int y0,int pre)
{
    if (best==0)
        return(true);
    if (dep+best>ans)
        return(false);
    for (int i=0;i<4;i++)
    {
        if (i==pre)
            continue;
        int x=x0+c[i][0],y=y0+c[i][1];
        if (x==0 || x>n)
            continue;
        if (y==0)
            y=4;
        if (y==5)
            y=1;
        swap(a[x0][y0],a[x][y]);
        if (dfs(dep+1,best+dis[a[x0][y0]][x0][y0]-dis[a[x0][y0]][x][y],x,y,i^1))
            return(true);
        swap(a[x0][y0],a[x][y]);
    }
    return(false);
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        n/=4;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=4;j++)
                scanf("%d",&a[i][j]);
        static int id=0;
        printf("Case %d: ",++id);
        if (!check())
            printf("impossible\n");
        else
        {
            int x0,y0,sum=0;
            for (int i=1;i<=n;i++)
                for (int j=1;j<=4;j++)
                    if (a[i][j]==1)
                        x0=i,y0=j;
                    else
                        sum+=dis[a[i][j]][i][j];
            bool flag=false;
            for (ans=0;ans<=25;ans++)
                if (dfs(0,sum,x0,y0,-1))
                {
                    flag=true;
                    printf("%d\n",ans);
                    break;
                }
            if (!flag)
                printf("impossible in 25 jumps\n");
        }
    }
    return(0);
}

