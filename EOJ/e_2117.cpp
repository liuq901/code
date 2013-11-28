#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        ll n,m;
        scanf("%I64d%I64d",&n,&m);
        printf("%I64d\n",n+m-__gcd(n,m));
    }
    return(0);
}

