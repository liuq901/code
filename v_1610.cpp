#include <cstdio>
#include <algorithm>
using namespace std;
const int N=1010;
typedef long long ll;
int a[N][N];
ll s[N][N],b[N][N],c[N][N];
ll query(ll x1,ll y1,ll x2,ll y2)
{
    return(s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1]);
}
ll work(int n,int m)
{
    for (int i=m;i<=n;i++)
        for (int j=m;j<=n;j++)
            b[i][j]=max(b[i][j-1],query(i-m+1,j-m+1,i,j));
    for (int i=m;i<=n;i++)
        for (int j=n-m+1;j;j--)
            c[i][j]=max(c[i][j+1],query(i-m+1,j,i,j+m-1));
    ll ret=0;
    for (int i=m;i<n;i++)
    {
        ll u=0,v=0;
        for (int j=1;j<=n;j++)
        {
            u=max(u,b[j][i]);
            v=max(v,c[j][i+1]);
        }
        ret=max(ret,u+v);
    }
    return(ret);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
        }
    ll ans=work(n,m);
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            swap(a[i][j],a[j][i]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
    ans=max(ans,work(n,m));
    printf("%I64d\n",ans);
    return(0);
}

