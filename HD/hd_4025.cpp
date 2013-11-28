#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
vector <int> s[30];
vector <ll> b;
vector <pair <ll,int> > hash;
int n,now[40],c[40],d[40],a[40][30];
void dfs(int dep,int final)
{
    if (dep==final+1)
    {
        ll state=0;
        for (int i=1;i<=n;i++)
            state=state<<2|now[i];
        b.push_back(state);
        return;
    }
    for (int i=0;i<s[dep].size();i++)
    {
        int x=s[dep][i];
        for (int j=1;j<=n;j++)
            now[j]^=x*a[j][dep];
        dfs(dep+1,final);
        for (int j=1;j<=n;j++)
            now[j]^=x*a[j][dep];
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
        for (int i=1;i<=m;i++)
        {
            s[i].clear();
            int K;
            scanf("%d",&K);
            while (K--)
            {
                int x;
                scanf("%d",&x);
                s[i].push_back(x);
            }
        }
        int p=m>>1;
        b.clear();
        memset(now,0,sizeof(now));
        dfs(1,p);
        sort(b.begin(),b.end());
        hash.clear();
        for (int i=0;i<b.size();)
        {
            int p=i;
            while (p<b.size() && b[p]==b[i])
                p++;
            hash.push_back(make_pair(b[i],p-i));
            i=p;
        }
        b.clear();
        memset(now,0,sizeof(now));
        dfs(p+1,m);
        sort(b.begin(),b.end());
        int t=0;
        ll ans=0;
        for (int i=0;i<b.size();i++)
        {
            while (t<hash.size() && hash[t].first<b[i])
                t++;
            if (t==hash.size())
                break;
            ans+=hash[t].second*(hash[t].first==b[i]);
        }
        printf("%I64d\n",ans);
    }
    return(0);
}

