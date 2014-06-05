#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b,ll &x,ll &y)
{
    if (b==0)
    {
        x=1,y=0;
        return(a);
    }
    ll ret=gcd(b,a%b,x,y);
    ll t=x;
    x=y;
    y=t-a/b*y;
    return(ret);
}
ll calc(ll f,ll n,bool key)
{
    if (f%n==0)
        return(f/n);
    if (!key)
        return(f*n<0?f/n:f/n+1);
    return(f*n<0?f/n-1:f/n);
}
ll solve(ll a,ll b,ll c,ll x1,ll x2,ll y1,ll y2)
{
    c*=-1;
    if (a==0 && b==0)
        return(c==0?(x2-x1+1)*(y2-y1+1):0);
    if (a==0)
        return(c%b==0 && c/b>=y1 && c/b<=y2?x2-x1+1:0);
    if (b==0)
        return(c%a==0 && c/a>=x1 && c/a<=x2?y2-y1+1:0);
    ll x,y,p=gcd(a,b,x,y);
    if (c%p!=0)
        return(0);
    a/=p,b/=p,c/=p;
    x*=c;
    x=(x%b+b)%b;
    ll l1=calc(x1-x,b,b<0),r1=calc(x2-x,b,b>0);
    y=(c-a*x)/b;
    ll r2=-calc(y1-y,a,a<0),l2=-calc(y2-y,a,a>0);
    if (b<0)
        swap(l1,r1);
    if (a<0)
        swap(l2,r2);
    return(max(0LL,min(r1,r2)-max(l1,l2)+1));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        ll a,b,c,x1,y1,x2,y2;
        scanf("%lld%lld%lld%lld%lld%lld%lld",&a,&b,&c,&x1,&x2,&y1,&y2);
        static int id=0;
        printf("Case %d: %lld\n",++id,solve(a,b,c,x1,x2,y1,y2));
    }
    return(0);
}

