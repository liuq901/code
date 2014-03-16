#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
set <int> S;
int a[5010],f[5010];
vector <int> p;
bool g[32010];
void init()
{
    int n=32000;
    for (int i=2;i*i<=n;i++)
    {
        if (g[i])
            continue;
        for (int j=i;i*j<=n;j++)
            g[i*j]=true;
    }
    for (int i=2;i<=n;i++)
        if (!g[i])
            p.push_back(i);
}
int calc(int x)
{
    int ret=0;
    for (int i=0;i<p.size();i++)
        while (x%p[i]==0)
        {
            x/=p[i];
            ret+=S.count(p[i])?-1:1;
        }
    if (x!=1)
        ret+=S.count(x)?-1:1;
    return(ret);
}
int main()
{
    init();
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int i=1;i<=m;i++)
    {
        int x;
        scanf("%d",&x);
        S.insert(x);
    }
    f[1]=a[1];
    for (int i=2;i<=n;i++)
        f[i]=__gcd(f[i-1],a[i]);
    for (int i=n;i;i--)
    {
        int p=calc(f[i]);
        if (p<0)
        {
            int tmp=f[i];
            for (int j=1;j<=i;j++)
            {
                f[j]/=tmp;
                a[j]/=tmp;
            }
        }
    }
    int ans=0;
    for (int i=1;i<=n;i++)
        ans+=calc(a[i]);
    printf("%d\n",ans);
    return(0);
}

