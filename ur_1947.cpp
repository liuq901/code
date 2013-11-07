#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
char a[15][10];
vector <pair <int,int> > adj[15][10];
bool vis[15][10];
void add(const pair <int,int> &a,const pair <int,int> &b)
{
    adj[a.first][a.second].push_back(b);
    adj[b.first][b.second].push_back(a);
}
bool dfs(int x,int y,int sum,int id)
{
    if (vis[x][y])
        return(false);
    vis[x][y]=true;
    if (sum>=3)
    {
        if (x==1 && id!=0)
            return(true);
        if (x==11 && id!=1)
            return(true);
        if (x%2==0 && y==0 && id!=2)
            return(true);
        if (x%2==0 && y==5 && id!=3)
            return(true);
    }
    for (int i=0;i<adj[x][y].size();i++)
        if (dfs(adj[x][y][i].first,adj[x][y][i].second,sum+1,id))
            return(true);
    return(false);
}
bool win()
{
    for (int i=1;i<=11;i++)
        for (int j=0;j<=5;j++)
            adj[i][j].clear();
    for (int i=1;i<=5;i++)
        for (int j=1;j<=5;j++)
        {
            if (a[i][j]=='*')
                continue;
            pair <int,int> U=make_pair(2*i-1,j);
            pair <int,int> D=make_pair(2*i+1,j);
            pair <int,int> L=make_pair(2*i,j-1);
            pair <int,int> R=make_pair(2*i,j);
            if (a[i][j]=='/')
            {
                add(L,U);
                add(R,D);
            }
            else
            {
                add(L,D);
                add(R,U);
            }
        }
    memset(vis,0,sizeof(vis));    
    for (int i=1;i<=5;i++)
    {
        if (dfs(1,i,0,0))
            return(true);
        if (dfs(11,i,0,1))
            return(true);
        if (dfs(2*i,0,0,2))
            return(true);
        if (dfs(2*i,5,0,3))
            return(true);
    }
    return(false);
}
int main()
{
    for (int i=1;i<=5;i++)
        scanf("%s",a[i]+1);
    if (win())
        printf("WIN\n");
    else
    {
        int x0,y0;
        for (int i=1;i<=5;i++)
            for (int j=1;j<=5;j++)
                if (a[i][j]=='*')
                {
                    x0=i,y0=j;
                    goto out;
                }
out:
        for (int i=y0+1;i<=5;i++)
        {
            swap(a[x0][i-1],a[x0][i]);
            if (win())
            {
                printf("L%d\n",i-y0);
                goto last;
            }
        }
        for (int i=5;i>y0;i--)
            swap(a[x0][i-1],a[x0][i]);
        for (int i=y0-1;i;i--)
        {
            swap(a[x0][i+1],a[x0][i]);
            if (win())
            {
                printf("R%d\n",y0-i);
                goto last;
            }
        }
        for (int i=1;i<y0;i++)
            swap(a[x0][i+1],a[x0][i]);
        for (int i=x0+1;i<=5;i++)
        {
            swap(a[i-1][y0],a[i][y0]);
            if (win())
            {
                printf("U%d\n",i-x0);
                goto last;
            }
        }
        for (int i=5;i>x0;i--)
            swap(a[i-1][y0],a[i][y0]);
        for (int i=x0-1;i;i--)
        {
            swap(a[i+1][y0],a[i][y0]);
            if (win())
            {
                printf("D%d\n",x0-i);
                goto last;
            }
        }
        printf("FAIL\n");
    }
last:
    return(0);
}

