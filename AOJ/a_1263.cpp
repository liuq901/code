#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int N=100000;
vector <int> ans,b[N];
int tot,dep[N],fa[N];
int a[60][60];
void addchain(int last,int len,int final)
{
    for (int i=1;i<len;i++)
    {
        b[++tot].clear();
        b[last].push_back(tot);
        b[tot].push_back(last);
        last=tot;
    }
    b[last].push_back(final);
    b[final].push_back(last);
}
void dfs(int x,int father)
{
    fa[x]=father;
    for (int i=0;i<b[x].size();i++)
    {
        int y=b[x][i];
        if (y==father)
            continue;
        dep[y]=dep[x]+1;
        dfs(y,x);
    }
}
int getnode(int x,int y,int delta)
{
    int now=x;
    while (1)
    {
        int u=dep[x]-dep[now],v=dep[now]-dep[y];
        if (u-v==delta)
            return(now);
        now=fa[now];
    }
}
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                scanf("%d",&a[i][j]);
        for (int i=1;i<=n;i++)
            b[i].clear();
        tot=n;
        addchain(1,a[1][2],2);
        for (int i=3;i<=n;i++)
        {
            int pos,len=1<<30;
            for (int j=1;j<i;j++)
            {
                dep[j]=0;
                dfs(j,0);
                for (int k=j+1;k<i;k++)
                {
                    int x=getnode(k,j,a[i][k]-a[i][j]),now=a[i][j]-dep[x];
                    if (now<len)
                    {
                        pos=x;
                        len=now;
                    }
                }
            }
            addchain(pos,len,i);
        }
        ans.clear();
        for (int i=n+1;i<=tot;i++)
            ans.push_back(b[i].size());
        sort(ans.begin(),ans.end());
        for (int i=0;i<ans.size();i++)
            printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
    }
    return(0);
}

