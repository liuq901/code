#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=100010;
int n,a[N];
ll s[N];
ll calc(int l,int r,int limit)
{
    ll ret=0;
    for (int i=0;i<=limit;i++)
    {
        int j=max(limit-2*i,0);
        int L=max(1,l-i),R=min(n,r+j);
        ret=max(ret,s[R]-s[L-1]);
        L=max(1,l-j),R=min(n,r+i);
        ret=max(ret,s[R]-s[L-1]);
    }
    return(ret);
}
int main()
{
    int P;
    while (scanf("%d%d",&n,&P)==2)
    {
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            s[i]=s[i-1]+a[i];
        }
        int m,T;
        scanf("%d%d",&m,&T);
        int step=min(T,m/2),l=P-step,r=P+step;
        ll ans=calc(l,r,T-step);
        if (m%2==1 && step<T)
            ans=max(ans,max(calc(l-1,r,T-step-1),calc(l,r+1,T-step-1)));
        printf("%lld\n",ans);
    }
    return(0);
}

