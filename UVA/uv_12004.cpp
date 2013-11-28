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
        int n;
        scanf("%d",&n);
        ll a=ll(n)*(n-1),b=4,p=__gcd(a,b);
        a/=p,b/=p;
        static int id=0;
        printf("Case %d: ",++id);
        if (b==1)
            printf("%lld\n",a);
        else
            printf("%lld/%lld\n",a,b);
    }
    return(0);
}

