#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
typedef long long ll;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char a[60][60];
int n,m,now,power[60][60],on[60][60],off[60][60],d[60][60];
vector <pair <int,int> > b;
vector <int> event[60][60];
queue <pair <int,int> > Q;
pair <int,int> pre[60][60];
bool vis[60][60];
void bfs(const pair <int,int> &S,const pair <int,int> &T)
{
    memset(vis,0,sizeof(vis));
    vis[S.first][S.second]=true;
    d[S.first][S.second]=now;
    Q.push(S);
    while (!Q.empty())
    {
        int x0=Q.front().first,y0=Q.front().second;
        for (int i=0;i<4;i++)
        {
            int x=x0+c[i][0],y=y0+c[i][1];
            if (x>0 && x<=n && y>0 && y<=m && a[x][y]=='.' && !vis[x][y])
            {
                vis[x][y]=true;
                pre[x][y]=Q.front();
                d[x][y]=d[x0][y0]+1;
                Q.push(make_pair(x,y));
            }
        }
        Q.pop();
    }
    pair <int,int> tmp=T;
    while (tmp!=S)
    {
        int x=tmp.first,y=tmp.second;
        event[x][y].push_back(d[x][y]);
        tmp=pre[x][y];
    }
    now=d[T.first][T.second];
}
ll calc(int x,int y)
{
    if (event[x][y].empty())
        return(0);
    ll ret=on[x][y]+off[x][y];
    for (int i=1;i<event[x][y].size();i++)
        ret+=min(ll(off[x][y]+on[x][y]),ll(power[x][y])*(event[x][y][i]-event[x][y][i-1]));
    return(ret);
}
int main()
{
    int K;
    scanf("%d%d%d",&n,&m,&K);
    for (int i=1;i<=n;i++)
        scanf("%s",a[i]+1);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            scanf("%d",&power[i][j]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            scanf("%d",&on[i][j]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            scanf("%d",&off[i][j]);
    for (int i=1;i<=K;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        b.push_back(make_pair(x+1,y+1));
    }
    event[b[0].first][b[0].second].push_back(0);
    for (int i=1;i<b.size();i++)
        bfs(b[i-1],b[i]);
    ll ans=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            ans+=calc(i,j);
    cout<<ans<<endl;
    return(0);
}

