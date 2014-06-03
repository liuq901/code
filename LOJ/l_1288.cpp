#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mod=1000000007;
int power(int x,int y)
{
    int ret=1;
    for (;y;y>>=1)
    {
        if (y&1)
            ret=ll(ret)*x%mod;
        x=ll(x)*x%mod;
    }
    return(ret);
}
bool f[310];
int m,p[310];
void init()
{
    const int n=300;
    for (int i=2;i*i<=n;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=n;j++)
            f[i*j]=true;
    }
    for (int i=2;i<=n;i++)
        if (!f[i])
            p[++m]=i;
}
int *a[70],c[70][1010];
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            ll x;
            scanf("%lld",&x);
            for (int j=1;j<=m;j++)
            {
                int cnt=0;
                while (x%p[j]==0)
                {
                    cnt++;
                    x/=p[j];
                }
                c[j][i]=cnt&1;
            }
        }
        for (int i=1;i<=m;i++)
            a[i]=c[i];
        int t=1;
        for (int i=1;i<=n;i++)
        {
            bool flag=false;
            for (int j=t;j<=m;j++)
                if (a[j][i])
                {
                    swap(a[t],a[j]);
                    flag=true;
                    break;
                }
            if (!flag)
                continue;
            for (int j=t+1;j<=m;j++)
            {
                int u=a[j][i];
                for (int k=i;k<=n;k++)
                    a[j][k]=a[j][k]-u*a[t][k]+2&1;
            }
            if (++t>min(n,m))
                break;
        }
        static int id=0;
        printf("Case %d: %d\n",++id,(power(2,n-t+1)-1+mod)%mod);
    }
    return(0);
}

