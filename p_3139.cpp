#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int now,vis[10300],a[20],to[2000],eight[12880],id[66000];
ll num[12880];
vector <int> v[10300];
void work(int id)
{
    int state=to[id],b[5];
    b[0]=0;
    for (int i=0;i<16;i++)
        if (state>>i&1)
            b[++b[0]]=a[i];
    sort(b+1,b+5);
    while (1)
    {
        int sum=0;
        for (int i=1;i<=4;i++)
            sum+=b[i]*i;
        if (vis[sum]!=now)
        {
            vis[sum]=now;
            v[sum].clear();
        }
        v[sum].push_back(state);
        if (!next_permutation(b+1,b+5))
            break;
    }
}
void calc(int u)
{
    if (vis[u]!=now)
        return;
    for (int i=0;i<v[u].size();i++)
        for (int j=i+1;j<v[u].size();j++)
        {
            if (v[u][i]&v[u][j])
                continue;
            num[id[v[u][i]|v[u][j]]]++;
        }
}
int main()
{
    int n=0,m=0;
    for (int i=0;i<1<<16;i++)
    {
        if (__builtin_popcount(i)==4)
        {
            id[i]=++n;
            to[n]=i;
        }
        if (__builtin_popcount(i)==8)
        {
            id[i]=++m;
            eight[m]=i;
        }
    }
    while (1)
    {
        scanf("%d",&a[0]);
        if (a[0]==0)
            break;
        for (int i=1;i<16;i++)
            scanf("%d",&a[i]);
        int limit=(1<<16)-1;
        now++;
        for (int i=1;i<=n;i++)
            work(i);
        memset(num,0,sizeof(num));
        for (int i=0;i<=10240;i++)
            calc(i);
        ll ans=0;
        for (int i=1;i<=m;i++)
            ans+=num[i]*num[id[eight[i]^limit]];
        static int id=0;
        printf("Case %d: %lld\n",++id,ans/2);
    }
    return(0);
}

