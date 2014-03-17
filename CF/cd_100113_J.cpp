#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll ans,now,L,delta,tot,R[40],s[40];
int n;
vector <ll> a;
ll Abs(ll x)
{
    return(x<0?-x:x);
}
vector <ll> b;
void update(int id)
{
    if (id>=0 && id<b.size())
    {
        ll tmp=tot+now+b[id];
        ll d=Abs(L-tmp);
        if (d<delta || d==delta && tmp<ans)
            ans=tmp,delta=d;
    }
}
void dfs(int dep,int limit,bool flag)
{
    if (dep==limit)
    {
        if (!flag)
            b.push_back(now);
        else
        {
            ll tmp=L-tot-now;
            int id=lower_bound(b.begin(),b.end(),tmp)-b.begin();
            update(id),update(id-1),update(id+1);
        }
        return;
    }
    dfs(dep+1,limit,flag);
    now+=a[dep];
    dfs(dep+1,limit,flag);
    now-=a[dep];
}
int main()
{
    freopen("splitter.in","r",stdin);
    freopen("splitter.out","w",stdout);
    cin>>n>>L;
    ll sum=0;
    for (int i=1;i<=n;i++)
    {
        cin>>R[i];
        sum+=R[i];
    }
    for (int i=1;i<=n;i++)
        cin>>s[i];
    for (int i=1;i<=n;i++)
    {
        ll tmp=L*R[i]/sum;
        ll p=tmp/s[i];
        tot+=p*s[i];
        if (L*R[i]%sum!=0 || tmp%s[i]!=0)
            a.push_back(s[i]);
    }
    n=a.size();
    int m=n/2;
    dfs(0,m,false);
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    ans=tot,delta=Abs(L-tot);
    dfs(m,n,true);
    cout<<ans<<endl;
}

