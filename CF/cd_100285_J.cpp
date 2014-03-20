#include <cstdio>
#include <queue>
#include <map>
using namespace std;
struct state
{
    int u,v,end;
    state(int u,int v,int end):u(u),v(v),end(end){}
};
inline bool operator <(const state &a,const state &b)
{
    return(a.u<b.u || a.u==b.u && (a.v<b.v || a.v==b.v && a.end<b.end));
}
int end[110],a[110][10],ans[110][110][2][10];
int main()
{
    int K,n;
    scanf("%d%d",&K,&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&end[i]);
    for (int i=1;i<=n;i++)
        for (int j=0;j<10;j++)
            scanf("%d",&a[i][j]);
    queue <state> Q;
    map <state,int> M;
    state init(1,0,end[1]);
    int tot=1;
    M[init]=0;
    Q.push(init);
    while (!Q.empty())
    {
        int u=Q.front().u,v=Q.front().v,w=Q.front().end;
        Q.pop();
        for (int i=0;i<10;i++)
        {
            int x=a[u][i],y=i==0?a[v][9]:a[u][i-1],z=i>=K?end[a[u][i-K]]:end[a[v][i+10-K]];
            state now(x,y,z);
            if (!M.count(now))
            {
                M[now]=tot++;
                Q.push(now);
            }
            ans[u][v][w][i]=M[now]+1;
        }
    }
    vector <state> tmp(M.size(),state(0,0,0));
    for (map <state,int>::iterator k=M.begin();k!=M.end();k++)
        tmp[k->second]=k->first;
    printf("Success\n%d\n",tmp.size());
    for (int i=0;i<tmp.size();i++)
        printf("%d%c",tmp[i].end,i+1==tmp.size()?'\n':' ');
    for (int i=0;i<tmp.size();i++)
    {
        int x=tmp[i].u,y=tmp[i].v,z=tmp[i].end;
        for (int j=0;j<10;j++)
            printf("%d%c",ans[x][y][z][j],j==9?'\n':' ');
    }
    return(0);
}

