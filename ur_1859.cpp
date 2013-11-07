#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=10000;
vector <vector <int> > g[3][10],tmp[3][10];
vector <int> block,adj[maxn];
char s[maxn],vis[maxn];
int n,m;
void dfs(int x)
{
    vis[x]=true;
    for (int i=0;i<adj[x].size();i++)
        if (!vis[adj[x][i]])
            dfs(adj[x][i]);
    block.push_back(x);
}
void init()
{
    scanf("%d%s%d",&n,s,&m);
    for (int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int tot=6*n;
    for (int i=1;i<=tot;i++)
        if (!vis[i])
        {
            block.clear();
            dfs(i);
            int cnt=0;
            for (int j=0;j<block.size();j++)
                cnt+=s[block[j]-1]=='0';
            g[cnt][block.size()-cnt].push_back(block);
        }
}
void merge(int x,int y,int u,int v,int a,int b,int limit)
{
    while (g[u][v].size()>=limit && g[a][b].size()>=limit)
    {
        g[x][y].push_back(g[u][v].back());
        g[u][v].pop_back();
        g[x][y].back().insert(g[x][y].back().end(),g[a][b].back().begin(),g[a][b].back().end());
        g[a][b].pop_back();
    }
}
void outv(const vector <int> &v)
{
    for (int i=0;i<v.size();i++)
        printf("%d%c",v[i],i==v.size()-1?'\n':' ');
}
bool flag[10][maxn];
bool check()
{
    memset(flag,0,sizeof(flag));
    for (int i=4;i>=0;i--)
        for (int j=0;j<g[2][i].size();j++)
        {
            int left=4-i;
            for (int k=4;k>=0;k--)
            {
                if (left<k)
                    continue;
                for (int l=0;l<g[0][k].size();l++)
                {
                    if (left<k)
                        break;
                    if (flag[k][l])
                        continue;
                    flag[k][l]=true;
                    g[2][i][j].insert(g[2][i][j].end(),g[0][k][l].begin(),g[0][k][l].end());
                    left-=k;
                }
            }
            if (left!=0)
                return(false);
        }
    int tot=0;
    for (int i=0;i<=4;i++)
        tot+=g[2][i].size();
    if (tot!=n)
        return(false);
    for (int i=0;i<=4;i++)
        for (int j=0;j<g[2][i].size();j++)
            outv(g[2][i][j]);
    return(true);
}
void save()
{
    for (int i=0;i<=2;i++)
        for (int j=0;j<=4;j++)
            tmp[i][j]=g[i][j];
}
void load()
{
    for (int i=0;i<=2;i++)
        for (int j=0;j<=4;j++)
            g[i][j]=tmp[i][j];
}
bool OK()
{
    int limit=min(g[1][0].size(),g[1][1].size());
    for (int i=0;i<=limit;i++)
    {
        int r0=g[1][0].size()-i,r1=g[1][1].size()-i;
        if (r0%2==1 || r1%2==1)
            continue;
        save();
        merge(2,1,1,0,1,1,limit-i+1);
        merge(2,2,1,1,1,1,2);
        merge(2,0,1,0,1,0,2);
        if (check())
            return(true);
        load();
    }
    return(false);
}
void MAIN()
{
    merge(2,4,1,4,1,0,1);
    merge(2,4,1,3,1,1,1);
    merge(2,3,1,3,1,0,1);
    merge(2,4,1,2,1,2,2);
    if (g[1][2].size()==1)
    {
        if (g[1][0].size())
        {
            save();
            merge(2,2,1,0,1,2,1);
            if (OK())
                return;
            load();
        }
        if (g[1][1].size())
        {
            save();
            merge(2,3,1,1,1,2,1);
            if (OK())
                return;
            load();
        }
    }
    else
        OK();
}
int main() 
{
    init();
    MAIN();
    return(0);
}

