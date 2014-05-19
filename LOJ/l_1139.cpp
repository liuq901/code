#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int c[4][2]={{1,0},{0,-1},{0,1},{-1,0}};
int ans,a[10][10],target[20][2];
bool check()
{
    int zero,m=0,b[20];
    for (int i=1;i<=3;i++)
        for (int j=1;j<=3;j++)
        {
            if (a[i][j]==0)
            {
                zero=i;
                continue;
            }
            b[++m]=a[i][j];
        }
    int ret=0;
    for (int i=1;i<=m;i++)
        for (int j=i+1;j<=m;j++)
            ret+=b[i]>b[j];
    return(ret%2==0);
}
void init()
{
    int t=0;
    for (int i=1;i<=3;i++)
        for (int j=1;j<=3;j++)
        {
            t++;
            target[t][0]=i;
            target[t][1]=j;
        }
}
int best()
{
    int ret=0;
    for (int i=1;i<=3;i++)
        for (int j=1;j<=3;j++)
        {
            int x=a[i][j];
            if (x==0)
                continue;
            ret+=abs(i-target[x][0])+abs(j-target[x][1]);
        }
    return(ret);
}
bool same()
{
    int t=0;
    for (int i=1;i<=3;i++)
        for (int j=1;j<=3;j++)
        {
            if (i==3 && j==3)
                break;
            if (a[i][j]!=++t)
                return(false);
        }
    return(true);
}
bool dfs(int dep,int x0,int y0,int prev)
{
    if (same())
        return(true);
    if (dep+best()>ans)
        return(false);
    for (int i=0;i<4;i++)
    {
        if (i==prev)
            continue;
        int x=x0+c[i][0],y=y0+c[i][1];
        if (x<=0 || x>3 || y<=0 || y>3)
            continue;
        swap(a[x0][y0],a[x][y]);
        if (dfs(dep+1,x,y,3-i))
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
        int Sx,Sy;
        for (int i=1;i<=3;i++)
            for (int j=1;j<=3;j++)
            {
                scanf("%d",&a[i][j]);
                if (a[i][j]==0)
                    Sx=i,Sy=j;
            }
        static int id=0;
        printf("Case %d: ",++id);
        if (!check())
        {
            printf("impossible\n");
            continue;
        }
        for (ans=best();;ans++)
            if (dfs(0,Sx,Sy,-1))
            {
                printf("%d\n",ans);
                break;
            }
    }
    return(0);
}

