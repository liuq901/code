#include <cstdio>
#include <set>
#include <vector>
using namespace std;
int t,cnt,b[310],c[310],a[610][2];
set <int> s[310];
vector <int> ans;
bool leaf[310],vis[310];
void dfs(int x,int father)
{
    leaf[x]=true;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        leaf[x]=false;
        dfs(y,x);
        s[x].insert(s[y].begin(),s[y].end());
    }
    if (leaf[x])
        s[x].insert(x);
}
int get(int x,int father,int p)
{
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        if (s[y].count(p))
            return(y);
    }
}
bool go(int x,int father)
{
    vis[x]=true;
    ans.push_back(x);
    if (leaf[x])
    {
        t++;
        return(true);
    }
    while (t<=cnt && s[x].count(c[t]))
    {
        int y=get(x,father,c[t]);
        if (vis[y])
            return(false);
        if (!go(y,x))
            return(false);
        ans.push_back(x);
    }
    return(true);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[i][0]=y,a[i][1]=b[x],b[x]=i;
        a[i+n][0]=x,a[i+n][1]=b[y],b[y]=i+n;
    }
    dfs(1,0);
    cnt=s[1].size();
    for (int i=1;i<=cnt;i++)
        scanf("%d",&c[i]);
    t=1;
    if (go(1,0))
        for (int i=0;i<ans.size();i++)
            printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
    else
        printf("-1\n");
    return(0);
}

