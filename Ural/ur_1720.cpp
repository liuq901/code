#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll get(ll x,ll n)
{
    return(n*(n+1)/2*x+n);
}
ll calc(ll Q,ll x,ll y)
{
    if (x==y)
        return(Q/x);
    ll n=x/(y-x);
    if (x%(y-x)!=0)
        n++;
    ll m=Q/y;
    if (n<=m)
        return(get(y-x,n)+Q-n*y);
    else
        return(get(y-x,m)+max(0LL,Q-(m+1)*x+1));
}
int main()
{
    ll x,y,l,r;
    cin>>x>>y>>l>>r;
    cout<<calc(r,x,y)-calc(l-1,x,y)<<endl;
    return(0);
}

