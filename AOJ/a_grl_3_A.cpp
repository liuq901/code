#include <cstdio>
#include <algorithm>
using namespace std;
int idx,dfn[100010],low[100010],b[100010],a[200010][2];
bool cut[100010];
void tarjan(int x,int father)
{
    dfn[x]=low[x]=++idx;
    int cnt=0;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        if (dfn[y]==0)
        {
            cnt++;
            tarjan(y,x);
            low[x]=min(low[x],low[y]);
            if (low[y]>=dfn[x] && father!=0)
                cut[x]=true;
        }
        else
            low[x]=min(low[x],dfn[y]);
    }
    if (father==0 && cnt>1)
        cut[x]=true;
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
        a[i+m][0]=x,a[i+m][1]=b[y],b[y]=i+m;
    }
    tarjan(1,0);
    for (int i=1;i<=n;i++)
        if (cut[i])
            printf("%d\n",i-1);
    return(0);
}

