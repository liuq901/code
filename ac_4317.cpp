#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector <ll> a;
void dfs(int dep,ll now)
{
    if (dep==10)
    {
        a.push_back(now*10);
        a.push_back(now*10+1);
        a.push_back(now*10+2);
        return;
    }
    for (int i=0;i<=3;i++)
        dfs(dep+1,now*10+i);
}
int main()
{
    dfs(1,0);
    sort(a.begin(),a.end());
    ll n;
    while (scanf("%lld",&n)==1)
        printf("%d\n",lower_bound(a.begin(),a.end(),n)-a.begin());
    return(0);
}

