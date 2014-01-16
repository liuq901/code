#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int idx,dfn[100010],low[100010],b[100010],a[200010][2];
vector <pair <int,int> > ans;
void tarjan(int x,int father)
{
    dfn[x]=low[x]=++idx;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        if (dfn[y]==0)
        {
            tarjan(y,x);
            low[x]=min(low[x],low[y]);
        }
        else
            low[x]=min(low[x],dfn[y]);
    }
    if (low[x]==dfn[x] && father!=0)
        ans.push_back(make_pair(min(x,father),max(x,father)));
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
    sort(ans.begin(),ans.end());
    for (int i=0;i<ans.size();i++)
        printf("%d %d\n",ans[i].first-1,ans[i].second-1);
    return(0);
}

