#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int a[20];
vector <pair <int,int> > b,ans;
void dfs(int l,int r,int dep)
{
    if (l>r)
        return;
    if (dep==0)
    {
        b.push_back(make_pair(l,r));
        return;
    }
    int p=a[dep];
    dfs(max(p,l+p),r+p,dep-1);
    dfs(p-r,min(p,p-l),dep-1);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    dfs(-1,1,n);
    sort(b.begin(),b.end());
    for (int i=0;i<b.size();i++)
        if (ans.empty() || b[i].first>ans.back().second)
            ans.push_back(b[i]);
        else
            ans.back().second=max(ans.back().second,b[i].second);
    printf("%d\n",ans.size());
    for (int i=0;i<ans.size();i++)
        printf("%d %d\n",ans[i].first,ans[i].second);
    return(0);
}

