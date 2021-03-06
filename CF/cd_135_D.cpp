#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
const int c[8][2]={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
char a[1010][1010];
bool vis[1010][1010];
int n,m,dep,f[1010][1010],pos[1010][1010];
vector <pair <int,int> > b;
void dfs(int x0,int y0)
{
    pos[x0][y0]=dep;
    for (int i=0;i<4;i++)
    {
        int x=x0+c[i][0],y=y0+c[i][1];
        if (x>0 && x<=n && y>0 && y<=m && !pos[x][y] && a[x][y]=='1')
            dfs(x,y);
    }
}
bool floodfill(int x0,int y0)
{
    bool flag=true;
    vis[x0][y0]=true;
    for (int i=0;i<8;i++)
    {
        int x=x0+c[i][0],y=y0+c[i][1];
        if (x==0 || x>n || y==0 || y>m)
            continue;
        if (a[x][y]=='1' && f[x][y]!=dep)
        {
            f[x][y]=dep;
            b.push_back(make_pair(x,y));
        }
        if (a[x][y]=='0' && !vis[x][y] && !floodfill(x,y))
            flag=false;
    }
    if (x0==1 || x0==n || y0==1 || y0==m)
        flag=false;
    return(flag);
}
bool check()
{
    if (b.size()==0)
        return(false);
    dep++;
    for (int i=0;i<b.size();i++)
    {
        int x=b[i].first,y=b[i].second;
        f[x][y]=dep;
    }
    for (int i=0;i<b.size();i++)
    {
        int x0=b[i].first,y0=b[i].second,cnt=0;
        for (int j=0;j<4;j++)
        {
            int x=x0+c[j][0],y=y0+c[j][1];
            if (x==0 || x>n || y==0 || y>m || f[x][y]!=dep)
                cnt++;
        }
        if (cnt!=2 || pos[x0][y0]!=pos[b[0].first][b[0].second])
            return(false);
    }
    return(true);
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%s",a[i]+1);
    int ans=0;
    for (int i=1;i<n;i++)
        for (int j=1;j<m;j++)
            if (a[i][j]=='1' && a[i][j+1]=='1' && a[i+1][j]=='1' && a[i+1][j+1]=='1')
                ans=4;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            if (a[i][j]=='0' || pos[i][j])
                continue;
            dep++;
            dfs(i,j);
        }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[i][j]=='0' && !vis[i][j])
            {
                b.clear();
                dep++;
                if (floodfill(i,j) && check())
                    ans=max(ans,int(b.size()));
            }
    printf("%d\n",ans);
    return(0);
}

