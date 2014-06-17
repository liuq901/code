#include <cstdio>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
const int c[4][2]={{0,1},{-1,0},{1,0},{0,-1}};
const char name[]="ENSW";
char a[20][20];
pair <int,int> move[20][20][4];
void prepare(int n,int m)
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            for (int k=1;k<4;k+=2)
            {
                int x=i+c[k][0],y=j+c[k][1];
                if (x==0 || x>n || y==0 || y>m)
                    move[i][j][k]=make_pair(-1,-1);
                else if (a[x][y]=='#')
                    move[i][j][k]=make_pair(i,j);
                else
                    move[i][j][k]=move[x][y][k];
            }
    for (int i=n;i;i--)
        for (int j=m;j;j--)
            for (int k=0;k<4;k+=2)
            {
                int x=i+c[k][0],y=j+c[k][1];
                if (x==0 || x>n || y==0 || y>m)
                    move[i][j][k]=make_pair(-1,-1);
                else if (a[x][y]=='#')
                    move[i][j][k]=make_pair(i,j);
                else
                    move[i][j][k]=move[x][y][k];
            }
}
bool vis[20][20];
bool dfs(int x,int y)
{
    if (x==-1)
        return(true);
    if (vis[x][y])
        return(false);
    vis[x][y]=true;
    for (int i=0;i<4;i++)
        if (dfs(move[x][y][i].first,move[x][y][i].second))
            return(true);
    return(false);
}
string solve(int n,int m)
{
    vector <pair <int,int> > init;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[i][j]=='.')
            {
                init.push_back(make_pair(i,j));
                memset(vis,0,sizeof(vis));
                if (!dfs(i,j))
                    return("Impossible");
            }
    map <vector <pair <int,int> >,string> M;
    queue <vector <pair <int,int> > > Q;
    Q.push(init);
    M[init]="";
    while (!Q.empty())
    {
        vector <pair <int,int> > x=Q.front();
        Q.pop();
        if (x.empty())
            return(M[x]);
        for (int i=0;i<4;i++)
        {
            vector <pair <int,int> > y;
            for (int j=0;j<x.size();j++)
            {
                pair <int,int> tmp=move[x[j].first][x[j].second][i];
                if (tmp.first!=-1)
                    y.push_back(tmp);
            }
            sort(y.begin(),y.end());
            y.erase(unique(y.begin(),y.end()),y.end());
            if (!M.count(y))
            {
                M[y]=M[x]+name[i];
                Q.push(y);
            }
        }
    }
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
            scanf("%s",a[i]+1);
        prepare(n,m);
        static int id=0;
        printf("Case %d: %s\n",++id,solve(n,m).c_str());
    }
    return(0);
}

