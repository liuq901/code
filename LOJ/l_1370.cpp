#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
bool f[2000010];
int m,p[2000010],phi[2000010];
map <int,int> M;
void init()
{
    const int n=2000000;
    for (int i=2;i*i<=n;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=n;j++)
        {
            f[i*j]=true;
            p[i*j]=i;
        }
    }
    phi[1]=1;
    for (int i=2;i<=n;i++)
    {
        if (!f[i])
        {
            phi[i]=i-1;
            continue;
        }
        int x=i;
        while (x%p[i]==0)
            x/=p[i];
        phi[i]=x==1?i/p[i]*(p[i]-1):phi[x]*phi[i/x];
    }
    int ma=-1;
    for (int i=2;i<=n;i++)
        if (phi[i]>ma)
            M[ma=phi[i]]=i;
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        ll ans=0;
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            ans+=M.lower_bound(x)->second;
        }
        static int id=0;
        printf("Case %d: %lld Xukha\n",++id,ans);
    }
    return(0);
}

