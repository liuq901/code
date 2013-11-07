#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;
bool check(ll x)
{
    int n=100000;
    for (int i=2;i<=n;i++)
    {
        if (i>=x)
            break;
        if (x%i!=0)
            continue;
        ll tmp=x/i,t=ll(sqrt(tmp)+1e-8);
        if (tmp%i==0 || t*t==tmp)
            return(false);
    }
    return(true);
}
ll c[60][60];
int main()
{
    int n=50;
    for (int i=0;i<=n;i++)
    {
        c[i][0]=c[i][i]=1;
        for (int j=1;j<i;j++)
            c[i][j]=c[i-1][j-1]+c[i-1][j];
    }
    vector <ll> ans;
    for (int i=0;i<=n;i++)
        for (int j=0;j<=i;j++)
            if (check(c[i][j]))
                ans.push_back(c[i][j]);
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    printf("%lld\n",accumulate(ans.begin(),ans.end(),0LL));
    return(0);
}

