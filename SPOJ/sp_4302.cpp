#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll Abs(ll x)
{
    return(x<0?-x:x);
}
bool check(ll n,ll k,ll x1,ll x2,ll y1,ll y2)
{
    if (n<k)
        swap(n,k);
    ll dx=Abs(x1-x2),dy=Abs(y1-y2);
    if (dx%__gcd(n,k)!=0)
        return(false);
    if (dy%__gcd(n,k)!=0)
        return(false);
    if ((n*dx+k*dy)%__gcd(__gcd(n*n+k*k,n*n-k*k),2*n*k)!=0)
        return(false);
    return(true);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,k,x1,y1,x2,y2;
        scanf("%d%d%d%d%d%d",&n,&k,&x1,&y1,&x2,&y2);
        printf("%s\n",check(n,k,x1,x2,y1,y2)?"TAK":"NIE");
    }
    return(0);
}

