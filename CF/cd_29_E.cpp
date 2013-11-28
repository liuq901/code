#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
struct state
{
    int x,y,op;
    state(int x,int y,int op):x(x),y(y),op(op){}
};
bool vis[510][510];
int n,inf,b[510],a[20010][2],d[510][510],pre[510][510][2];
vector <int> ans[2];
queue <state> Q;
void bfs(int x0,int y0)
{
    Q.push(state(x0,y0,0));
    memset(d,63,sizeof(d));
    inf=d[0][0];
    d[x0][y0]=0;
    while (!Q.empty())
    {
        int p=Q.front().x,q=Q.front().y,op=Q.front().op;
        Q.pop();
        if (op==0)
            for (int i=b[p];i;i=a[i][1])
            {
                int x=a[i][0];
                if (!vis[x][q])
                {
                    vis[x][q]=true;
                    Q.push(state(x,q,p));
                }
            }
        else
            for (int i=b[q];i;i=a[i][1])
            {
                int y=a[i][0];
                if (p!=y && d[p][y]==inf)
                {
                    d[p][y]=d[op][q]+1;
                    pre[p][y][0]=op;
                    pre[p][y][1]=q;
                    Q.push(state(p,y,0));
                }
            }
    }
}
void print(int x,int y)
{
    if (x!=1 || y!=n)
        print(pre[x][y][0],pre[x][y][1]);    
    ans[0].push_back(x);
    ans[1].push_back(y);
}
int main()
{
    int m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[i][0]=y,a[i][1]=b[x],b[x]=i;
        a[i+m][0]=x,a[i+m][1]=b[y],b[y]=i+m;
    }
    bfs(1,n);
    if (d[n][1]==inf)
        printf("-1\n");
    else
    {
        printf("%d\n",d[n][1]);
        print(n,1);
        for (int i=0;i<ans[0].size();i++)
            printf("%d%c",ans[0][i],i==ans[0].size()-1?'\n':' ');
        for (int i=0;i<ans[1].size();i++)
            printf("%d%c",ans[1][i],i==ans[1].size()-1?'\n':' ');
    }
    return(0);
}

