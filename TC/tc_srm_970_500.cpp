#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
struct TreesAnalysis
{
    vector <int> a[4010],b[4010];
    int idx,f[4010],tot[4010],fa[4010],vis[4010],cnt[4010];
    ll treeSimilarity(vector <int> tree1,vector <int> tree2)
    {
        int n=tree1.size()+1;
        for (int i=1;i<=n;i++)
        {
            a[i].clear();
            b[i].clear();
        }
        for (int i=1;i<n;i++)
        {
            int x=tree1[i-1]+1;
            a[i].push_back(x);
            a[x].push_back(i);
            x=tree2[i-1]+1;
            b[i].push_back(x);
            b[x].push_back(i);
        }
        idx++;
        dfs(1,0);
        ll ans=0;
        for (int i=2;i<=n;i++)
        {
            idx++;
            dfs(i,fa[i]);
            dp(1,0);
            for (int j=2;j<=n;j++)
            {
                int x=cnt[i],y=n-cnt[i];
                int u=f[j],v=tot[j]-f[j];
                ans+=max(max(u*u,v*v),max((x-u)*(x-u),(y-v)*(y-v)));
            }
        }
        return(ans);
    }
    void dfs(int x,int father)
    {
        cnt[x]=1;
        vis[x]=idx;
        for (int i=0;i<a[x].size();i++)
        {
            int y=a[x][i];
            if (y==father)
                continue;
            fa[y]=x;
            dfs(y,x);
            cnt[x]+=cnt[y];
        }
    }
    void dp(int x,int father)
    {
        f[x]=vis[x]==idx;
        tot[x]=1;
        for (int i=0;i<b[x].size();i++)
        {
            int y=b[x][i];
            if (y==father)
                continue;
            dp(y,x);
            f[x]+=f[y];
            tot[x]+=tot[y];
        }
    }
};
int main(){}

