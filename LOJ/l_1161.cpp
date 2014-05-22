#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int m,p[10010];
bool f[10010];
ll ans,c[10010];
void init()
{
    int n=10000;
    for (int i=2;i*i<=n;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=n;j++)
            f[i*j]=true;
    }
    for (int i=2;i<=n;i++)
    {
        if (!f[i])
            p[++m]=i;
        c[i]=ll(i)*(i-1)*(i-2)*(i-3)/24;
    }
}
void dfs(int first,int dep,int now,int a[],int n)
{
    if (dep&1)
        ans+=c[n];
    else
        ans-=c[n];
    for (int i=first;i<=m;i++)
    {
        int x=now*p[i];
        if (x>a[n])
            break;
        int t=0,b[n+10];
        for (int j=1;j<=n;j++)
            if (a[j]%x==0)
                b[++t]=a[j];
        if (t>=4)
            dfs(i+1,dep+1,x,b,t);
    }
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
        int a[n+10];
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        ans=0;
        dfs(1,1,1,a,n);
        static int id=0;
        printf("Case %d: %lld\n",++id,ans);
    }
    return(0);
}

