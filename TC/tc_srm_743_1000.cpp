#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
struct TheLuckyBasesDivOne
{
    vector <ll> a;
    ll find(ll n)
    {
        if (lucky(n))
            return(-1);
        ll ans=0;
        for (ll i=2;i*i*i<=n;i++)
            ans+=lucky(n,i);
        dfs(4,n);
        dfs(7,n);
        sort(a.begin(),a.end());
        for (int i=0;i<a.size();i++)
        {
            ll x=a[i];
            if (x*x>n)
                break;
            for (int j=0;j<a.size();j++)
            {
                ll y=a[j],u=max(x,y);
                if (x*u+y>n)
                    break;
                ll p=(n-y)/x;
                ans+=check(x,y,n,p);
            }
        }
        for (int i=0;i<a.size();i++)
        {
            ll x=a[i];
            if (x*x*x>n)
                break;
            for (int j=0;j<a.size();j++)
            {
                ll y=a[j],u=max(x,y);
                if (x*u*u+y*u>n)
                    break;
                for (int k=0;k<a.size();k++)
                {
                    ll z=a[k],v=max(u,z);
                    if (x*v*v+y*v+z>n)
                        break;
                    ll p=get(x,y,n-z);
                    ans+=check(x,y,z,n,p);
                }
            }
        }
        return(ans);
    }
    bool lucky(ll n)
    {
        if (n==4 || n==7)
            return(true);
        if (n<10)
            return(false);
        if (n%10!=4 && n%10!=7)
            return(false);
        return(lucky(n/10));
    }
    bool lucky(ll n,int x)
    {
        while (n)
        {
            if (!lucky(n%x))
                return(false);
            n/=x;
        }
        return(true);
    }
    void dfs(ll now,ll limit)
    {
        if (now>limit)
            return;
        a.push_back(now);
        dfs(now*10+4,limit);
        dfs(now*10+7,limit);
    }
    ll get(ll a,ll b,ll c)
    {
        ll l=0,r=min(ll(sqrt(c/a)),c/b)+10;
        while (l<=r)
        {
            ll x=l+r>>1,now=a*x*x+b*x;
            if (now==c)
                return(x);
            if (now<c)
                l=x+1;
            else
                r=x-1;
        }
        return(-1);
    }
    bool check(ll x,ll y,ll n,ll p)
    {
        if (x>=p || y>=p)
            return(false);
        if (n%p!=y)
            return(false);
        n/=p;
        return(n==x);
    }
    bool check(ll x,ll y,ll z,ll n,ll p)
    {
        if (x>=p || y>=p || z>=p)
            return(false);
        if (n%p!=z)
            return(false);
        n/=p;
        if (n%p!=y)
            return(false);
        n/=p;
        return(n==x);
    }
};
int main(){}

