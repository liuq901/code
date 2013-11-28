#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=1000010;
int sum[N],q[N],v[N],fa[N],b[N],a[N][2];
ll bfs(int S)
{
    ll ans=0;
    int l,r;
    q[l=r=1]=S;
    while (l<=r)
    {
        int x=q[l++];
        for (int i=b[x];i;i=a[i][1])
        {
            int y=a[i][0];
            q[++r]=y;
        }
    }
    for (int i=r;i;i--)
    {
        int x=q[i];
        sum[x]=v[x];
        vector <int> s;
        for (int i=b[x];i;i=a[i][1])
        {
            int y=a[i][0];
            s.push_back(sum[y]);
            sum[x]+=sum[y];
        }
        sort(s.begin(),s.end());
        ll now=0;
        for (int i=0;i<s.size();i++)
        {
            ans+=now;
            now+=s[i];
        }
    }
    return(ans);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d",&v[i],&fa[i]);
        fa[i]++;
        if (fa[i]!=0)
            a[i][0]=i,a[i][1]=b[fa[i]],b[fa[i]]=i;
    }
    ll ans=0;
    for (int i=1;i<=n;i++)
        if (fa[i]==0)
            ans+=bfs(i);
    cout<<ans<<endl;
    return(0);
}

