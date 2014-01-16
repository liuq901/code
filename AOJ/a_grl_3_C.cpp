#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
int idx,tot,c[10010],dfn[10010],low[10010],b[10010],a[30010][2];
bool flag[10010];
stack <int> S;
void tarjan(int x)
{
    dfn[x]=low[x]=++idx;
    flag[x]=true;
    S.push(x);
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (dfn[y]==0)
        {
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }
        else if (flag[y])
            low[x]=min(low[x],dfn[y]);
    }
    if (low[x]==dfn[x])
    {
        tot++;
        while (1)
        {
            int y=S.top();
            S.pop();
            c[y]=tot;
            flag[y]=false;
            if (x==y)
                break;
        }
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x++,y++;
        a[i][0]=y,a[i][1]=b[x],b[x]=i;
    }
    for (int i=1;i<=n;i++)
        if (dfn[i]==0)
            tarjan(i);
    int Q;
    scanf("%d",&Q);
    while (Q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x++,y++;
        printf("%d\n",c[x]==c[y]);
    }
    return(0);
}

