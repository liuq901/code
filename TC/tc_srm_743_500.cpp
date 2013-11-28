#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
struct TheLuckyGameDivOne
{
    vector <ll> a;
    int find(ll A,ll B,ll jlen,ll blen)
    {
        dfs(A,B,0);
        sort(a.begin(),a.end());
        int ans=0;
        for (int i=0;i<a.size();i++)
        {
            ll l=max(A,a[i]-blen+1),r=l+jlen-1;
            if (r>B)
                break;
            ans=max(ans,solve(l,r,blen));
        }
        return(ans);
    }
    void dfs(ll A,ll B,ll now)
    {
        if (now>B)
            return;
        if (now>=A)
            a.push_back(now);
        dfs(A,B,now*10+4);
        dfs(A,B,now*10+7);
    }
    int solve(ll A,ll B,ll blen)
    {
        int ans=get(B-blen+1,B);
        for (int i=0;i<a.size();i++)
        {
            ll l=max(A,a[i]-blen),r=l+blen-1;
            if (r>B)
                break;
            ans=min(ans,get(l,r));
        }
        return(ans);
    }
    int get(ll A,ll B)
    {
        return(upper_bound(a.begin(),a.end(),B)-lower_bound(a.begin(),a.end(),A));
    }
};
int main(){}

