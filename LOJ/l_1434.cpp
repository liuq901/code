#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
const int c[9][2]={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1},{0,0}};
const string name[9]={"U","D","L","R","UL","UR","DL","DR","*"};
struct state
{
    int x,y,len;
    state(){}
    state(int x,int y,int len):x(x),y(y),len(len){}
};
char s[20],a[40][40];
state pre[40][40][20];
int way[40][40][20];
bool vis[40][40][20];
int n,m;
void print(const state &s)
{
    if (s.len==1)
    {
        printf("found: (%d,%d)",s.x,s.y);
        return;
    }
    print(pre[s.x][s.y][s.len]);
    printf(", %s",name[way[s.x][s.y][s.len]].c_str());
}
bool bfs()
{
    int len=strlen(s+1);
    memset(vis,0,sizeof(vis));
    queue <state> Q;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[i][j]==s[1])
            {
                vis[i][j][1]=true;
                Q.push(state(i,j,1));
            }
    while (!Q.empty())
    {
        int x0=Q.front().x,y0=Q.front().y,dep=Q.front().len;
        if (dep==len)
        {
            print(Q.front());
            printf("\n");
            return(true);
        }
        for (int i=0;i<9;i++)
        {
            int x=x0+c[i][0],y=y0+c[i][1];
            if (x==0 || x>n || y==0 || y>m || a[x][y]!=s[dep+1] || vis[x][y][dep+1])
                continue;
            way[x][y][dep+1]=i;
            vis[x][y][dep+1]=true;
            pre[x][y][dep+1]=Q.front();
            Q.push(state(x,y,dep+1));
        }
        Q.pop();
    }
    return(false);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            scanf("%s",a[i]+1);
        static int id=0;
        printf("Case %d:\n",++id);
        int Q;
        scanf("%d",&Q);
        while (Q--)
        {
            scanf("%s",s+1);
            printf("%s ",s+1);
            if (!bfs())
                printf("not found\n");
        }
    }
    return(0);
}

