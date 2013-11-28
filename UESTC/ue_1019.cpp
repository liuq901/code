#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
    while (1)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if (a==0 && b==0)
            break;
        if (__gcd(a,b)!=1)
            printf("Inf\n");
        else
            printf("%lld\n",ll(b)*(a-1)-a);
    }
    return(0);
}

