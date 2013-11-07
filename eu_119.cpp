#include <cstdio>
#include <cmath>
#include <set>
using namespace std;
typedef long long ll;
set <ll> S;
void calc(int x,int y)
{
    ll now=1;
    for (int i=1;i<=y;i++)
        now*=x;
    int sum=0;
    ll tmp=now;
    while (tmp)
    {
        sum+=tmp%10;
        tmp/=10;
    }
    if (sum==x)
        S.insert(now);
}
int main()
{
    int ans=0;
    for (int i=1;i<=120;i++)
        for (int j=1;j<=10;j++)
            calc(i,j);
    int now=0;
    for (set <ll>::iterator k=S.begin();k!=S.end();k++)
    {
        if (*k<10)
            continue;
        if (++now==30)
        {
            printf("%lld\n",*k);
            break;
        }
    }
    return(0);
}

