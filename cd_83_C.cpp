#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <utility>
#include <queue>
using namespace std;
typedef pair <int,int> state;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool f[30],vis[60][60];
char a[60][60];
int n,m,K,d[60][60];
string ans;
state S,T;
queue <state> Q;
vector <state> b;
void bfs()
{
    memset(d,63,sizeof(d));
    int inf=d[0][0];
    d[T.first][T.second]=0;
    Q.push(T);
    while (!Q.empty())
    {
        int x0=Q.front().first,y0=Q.front().second;
        Q.pop();
        for (int i=0;i<4;i++)
        {
            int x=x0+c[i][0],y=y0+c[i][1];
            if (x>0 && x<=n && y>0 && y<=m && d[x0][y0]+1<d[x][y] && (a[x][y]=='S' || f[a[x][y]-'a']))
            {
                d[x][y]=d[x0][y0]+1;
                Q.push(make_pair(x,y));
            }
        }
    }
    if (d[S.first][S.second]==inf)
        return;
    string now;
    Q.push(S);
    memset(vis,0,sizeof(vis));
    vis[S.first][S.second]=true;
    while (1)
    {
        char ch='z'+1;
        b.clear();
        while (!Q.empty())
        {
            int x0=Q.front().first,y0=Q.front().second;
            Q.pop();
            for (int i=0;i<4;i++)
            {
                int x=x0+c[i][0],y=y0+c[i][1];
                if (x>0 && x<=n && y>0 && y<=m && d[x0][y0]==d[x][y]+1)
                {
                    if (a[x][y]<ch)
                    {
                        b.clear();
                        ch=a[x][y];
                    }
                    if (a[x][y]==ch && !vis[x][y])
                        b.push_back(make_pair(x,y));
                    vis[x][y]=true;
                }
            }
        }
        if (b.size()==0 || ch=='T')
            break;
        now+=ch;
        for (int i=0;i<b.size();i++)
            Q.push(b[i]);
    }
    if (now.size()<ans.size() || now.size()==ans.size() && now<ans)
        ans=now;
}
void dfs(int dep,int last)
{
    if (dep>K)
        return;
    bfs();
    for (int i=last+1;i<26;i++)
    {
        f[i]=true;
        dfs(dep+1,i);
        f[i]=false;
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&K);
    for (int i=1;i<=n;i++)
        scanf("%s",a[i]+1);
    for (int i=1;i<=n*m;i++)
        ans+='z';
    ans+='z';
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            if (a[i][j]=='S')
                S=make_pair(i,j);
            if (a[i][j]=='T')
                T=make_pair(i,j);
        }
    for (int i=0;i<26;i++)
    {
        f[i]=true;
        dfs(1,i);
        f[i]=false;
    }
    if (ans.size()==n*m+1)
        printf("-1\n");
    else
        printf("%s\n",ans.c_str());
    return(0);
}

