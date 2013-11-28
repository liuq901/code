#include <cstdio>
typedef long long ll;
struct TheAlmostLuckyNumbersDivOne
{
    ll ans;
    ll find(ll a,ll b)
    {
        return(calc(b)-calc(a-1));
    }
    ll calc(ll x)
    {
        ans=0;
        for (int i=1;i<10;i++)
            dfs(x,i,i==4 || i==7);
        return(ans);
    }
    void dfs(ll limit,ll now,bool lucky)
    {
        if (now>limit)
            return;
        ans++;
        for (int i=0;i<10;i++)
        {
            if (!lucky && i!=4 && i!=7)
                continue;
            dfs(limit,now*10+i,lucky && (i==4 || i==7));
        }
    }
};
int main(){}

