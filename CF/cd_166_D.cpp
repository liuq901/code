#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int dep,b[100010],vis[100010];
vector <int> adj[100010];
bool find(int x)
{
    if (!x)
        return(true);
    for (int i=0;i<adj[x].size();i++)
    {
        int y=adj[x][i];
        if (vis[y]==dep)
            continue;
        vis[y]=dep;
        if (find(b[y]))
        {
            b[y]=x;
            return(true);
        }
    }
    return(false);
}
int a[100010],c[100010],s[100010];
inline bool cmp1(int x,int y)
{
    return(s[x]<s[y]);
}
inline bool cmp2(int x,int y)
{
    return(c[x]>c[y]);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d",&c[i],&s[i]);
        a[i]=i;
    }
    sort(a+1,a+n+1,cmp1);
    int m;
    scanf("%d",&m);
    c[0]=1<<30;
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        s[0]=y;
        int t=lower_bound(a+1,a+n+1,0,cmp1)-a,k=t<=n?a[t]:0;
        if (c[k]<=x && s[k]==y)
            adj[k].push_back(i);
        s[0]=y+1;
        t=lower_bound(a+1,a+n+1,0,cmp1)-a,k=t<=n?a[t]:0;
        if (c[k]<=x && s[k]==y+1)
            adj[k].push_back(i);
    }
    sort(a+1,a+n+1,cmp2);
    ll ans=0;
    for (int i=1;i<=n;i++)
    {
        int x=a[i];
        dep++;
        if (find(x))
            ans+=c[x];
    }
    printf("%I64d\n%d\n",ans,m-count(b+1,b+m+1,0));
    for (int i=1;i<=m;i++)
        if (b[i])
            printf("%d %d\n",i,b[i]);
    return(0);
}

