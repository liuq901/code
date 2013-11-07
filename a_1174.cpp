#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int C[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
struct state
{
    int a[8][8];
};
int n,m,c,ans;
bool f[8][8];
state begin;
int floodfill(const state &now,int x0,int y0)
{
    f[x0][y0]=true;
    int ret=1;
    for (int i=0;i<4;i++)
    {
        int x=x0+C[i][0],y=y0+C[i][1];
        if (x<0 || x==n || y<0 || y==m || now.a[x][y]!=now.a[x0][y0] || f[x][y])
            continue;
        ret+=floodfill(now,x,y);
    }
    return(ret);
}
state change(const state &now,int c)
{
    memset(f,0,sizeof(f));
    floodfill(now,0,0);
    state ret=now;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            if (f[i][j])
                ret.a[i][j]=c;
    return(ret);
}
void dfs(const state &now,int dep)
{
    if (dep==6)
    {
        if (now.a[0][0]==c)
        {
            memset(f,0,sizeof(f));
            ans=max(ans,floodfill(now,0,0));
        }
        return;
    }
    for (int i=1;i<=6;i++)
        dfs(change(now,i),dep+1);
}
int main()
{
    while (1)
    {
        scanf("%d%d%d",&n,&m,&c);
        if (n==0 && m==0 && c==0)
            break;
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                scanf("%d",&begin.a[i][j]);
        ans=0;
        dfs(begin,1);
        printf("%d\n",ans);
    }
    return(0);
}

