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
        ll x1,y1,x2,y2;
        scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
        ll x=abs(x2-x1),y=abs(y2-y1);
        static int id=0;
        printf("Case %d: %lld\n",++id,__gcd(x,y)+1);
    }
    return(0);
}

