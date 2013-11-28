#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int a[1010][1010];
ll C(int a,int b)
{
    if (a<b)
        return(0);
    ll ret=1;
    for (int i=0;i<b;i++)
        ret*=(a-i);
    for (int i=1;i<=b;i++)
        ret/=i;
    return(ret);
}
int main()
{
    for (int i=1;i<=1000;i++)
        for (int j=1;j<=1000;j++)
            a[i][j]=__gcd(i,j);
    while (1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        ll ans=C((n+1)*(m+1),3)-C(n+1,3)*(m+1)-C(m+1,3)*(n+1);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                ans-=2LL*(a[i][j]-1)*(n-i+1)*(m-j+1);
        static int id=0;
        printf("Case %d: %lld\n",++id,ans);
    }
    return(0);
}

