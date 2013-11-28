#include <cstdio>
#include <vector>
#include <map>
using namespace std;
bool vis[1010];
int a[1010];
vector <int> b[1010];
multimap <int,int> M;
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int K;
        scanf("%d%d",&a[i],&K);
        b[i].resize(K);
        for (int j=0;j<K;j++)
            scanf("%d",&b[i][j]);
    }
    M.insert(make_pair(a[1],1));
    vis[1]=true;
    int ans=0;
    while (!M.empty())
    {
        int t=M.begin()->first,x=M.begin()->second;
        M.erase(M.begin());
        ans=max(ans,t);
        for (int i=0;i<b[x].size();i++)
        {
            int y=b[x][i];
            if (!vis[y])
            {
                vis[y]=true;
                M.insert(make_pair(t+a[y],y));
            }
        }
    }
    printf("%d\n",ans);
    return(0);
}

